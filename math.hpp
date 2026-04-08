#ifndef LIBMATH_MATH_HPP
#define LIBMATH_MATH_HPP

#include <climits>

namespace math {


long long add(int a, int b, bool& error) {
    if ((a > 0 && b > 0 && a > LLONG_MAX - b) ||
        (a < 0 && b < 0 && a < LLONG_MIN - b)) {
        error = true;
        return 0;
    }
    return a + b;
}


long long subtract(int a, int b, bool& error) {
    if ((b > 0 && a < LLONG_MIN + b) ||
        (b < 0 && a > LLONG_MAX + b)) {
        error = true;
        return 0;
    }
    return a - b;
}


long long multiply(int a, int b, bool& error) {
    if (a != 0 && b != 0) {
        if ((a > 0 && b > 0 && a > LLONG_MAX / b) ||
            (a < 0 && b < 0 && a < LLONG_MAX / b) ||
            (a > 0 && b < 0 && b < LLONG_MIN / a) ||
            (a < 0 && b > 0 && a < LLONG_MIN / b)) {
            error = true;
            return 0;
        }
    }
    return a * b;
}


long long divide(int a, int b, bool& error) {
    if (b == 0) {
        error = true;
        return 0;
    }
    return a / b;
}


long long power(int base, int exp, bool& error) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        if (result > LLONG_MAX / base) {
            error = true;
            return 0;
        }
        result *= base;
    }
    return result;
}


long long factorial(int n, bool& error) {
    if (n < 0) {
        error = true;
        return 0;
    }
    if (n <= 1) return 1;
    
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        if (result > LLONG_MAX / i) {
            error = true;
            return 0;
        }
        result *= i;
    }
    return result;
}

}

#endif
