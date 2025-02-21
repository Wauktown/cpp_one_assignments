#ifndef ALGO_H_
#define ALGO_H_

#include "types.hpp"

long fibonacci(const int n)
{
    if (n <= 1) {
        return n;
}
long a = 0, b = 1;
for (int i = 2; i <= n; ++i) {
long temp  = a + b;
a = b;
b = temp;
}
return b;
}

int linear_search(Array * a, const int target)
{
    return 0;
}

long factorial(const int n)
{
    return 0;
}

#endif // ALGO_H_
