#ifndef LIBMATH_MATH_HPP
#define LIBMATH_MATH_HPP

#include <climits>   // для LLONG_MAX

namespace math {

// Возведение в степень с проверкой переполнения
long long exponentiation(int base, int exp, bool& error) {
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

// Факториал с проверкой переполнения
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

} // namespace math

#endif // LIBMATH_MATH_HPP