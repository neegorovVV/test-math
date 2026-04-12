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
    if (b == 0) 
    {
        error = true;
        return 0;
    }

    if (a == INT_MIN && b == -1) 
    {
        error = true;
        return 0;
    }
    
    return a / b;
}


long long exponentiation(int base, int exp, bool& error) {

    long long result = 1;

    if(base == 0)
    {
        return 0;
    }

    if(base == 0 && exp == 0)
    {   
        return 1;
    }

    for (int i = 0; i < exp; i++) {

        if (result > LLONG_MAX / base) {
            error = true;
            return 0;
        }
        result *= base;
    }
    return result;
}


long long factorial(int a, bool& error)
{   
    if (a < 0)
    {
        error = true;
        return 0;
    }
    
    if (a <= 1)
    {
        return 1;
    }
    
    long long result = factorial(a - 1, error);
    
    if (error)
    {
        return 0;
    }
    
    if (result > LLONG_MAX / a)
    {
        error = true;
        return 0;
    }

    return a * result;
}

}
#endif

