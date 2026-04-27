#pragma once

#include <climits>
#include <stdexcept>

namespace mathoop 
{

long long add(int a, int b) 
{
  if ((a > 0 && b > 0 && a > INT_MAX  - b) || (a < 0 && b < 0 && a < INT_MIN - b))     
         throw std::runtime_error("Overflow error during add operation");

     long long result = 1;
     result = a + b;
     return result;
}


long long subtract(int a, int b) 
{
      if ((b > 0 && a < INT_MIN + b) || (b < 0 && a > INT_MAX  + b))
        throw std::runtime_error("Overflow error during subtract operation");
    long long result = 1;
    result = a - b;
    return result;
}


long long multiply(int a, int b)
{
      if (a != 0 && b != 0) 
    {
        if ((a > 0 && b > 0 && a > INT_MAX  / b) ||
            (a < 0 && b < 0 && a < INT_MAX  / b) ||
            (a > 0 && b < 0 && b < INT_MIN / a) ||
            (a < 0 && b > 0 && a < INT_MIN / b)) 
                 throw std::runtime_error("Overflow error during multiply operation");
    }
    long long result = 1;
    result = a * b;
    return result;
}


long long divide(int a, int b) 
{
     if(b == 0)
        throw std::runtime_error("Error: Divison by zero");

    if(a == INT_MIN && b == -1)
        throw std::runtime_error("Overflow error during divide operation");

    long long result = 1;
    result = a / b;
    return result;
}


long long exponentiation(int base, int exp)
{

    long long result = 1;

    if(base == 0 && exp == 0)
        return 1;
    if(base == 0)
        return 0;
    if(exp < 0)
        throw std::runtime_error("Error: negative exp leads to non int result which is no supported");
    for (size_t i = 0; i < exp; i++)
    {
        if (base > 0 && result > LLONG_MAX / base) 
           throw std::runtime_error("Overflow error during exponentiation operation");

        if (base < 0 && result > LLONG_MAX / -base) 
           throw std::runtime_error("Overflow error during exponentiation operation");
        
        result *= base;
    }

    return result;
}


long long factorial(int base)
{   
   if(base < 0)
        throw std::runtime_error("Error: negative factorail base");
    if(base <= 1)
        return 1;

    long long result = factorial(base - 1);

    if(result > LLONG_MAX / base)
        throw std::runtime_error("Overflow error during factorial operation");

        
    return base * result;
}

          }

