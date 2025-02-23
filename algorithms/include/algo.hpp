#ifndef ALGO_H_
#define ALGO_H_

#include "types.hpp"
#include <stdio.h>
#include <stdint.h>

typedef struct {
    int *data;
    size_t len;
} Array;

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
    for (size_t i = 0; i <a->len; ++i {
        if (a->data[i] == target) {
        return i;
     }
    }
    return -1;
}

long factorial(const int n)
{
    if (n == o || n == 1) {
        return 1;
    }
    long result = 1;

    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}
int main() {
    int n = 10;
printf("Fibonacci of %d is: %11d\n", n, fibonacci(n));

int arr[] = {5, 2, 9, 3, 7, 8};
Array a = {arr, 6};

int target = 7;
int index = linear_search(8a, target);
if (index != -1) {
printf("Element %d found at index: %d\n", target, index);
}else{
printf("Element %d not found in the array\n", target);
}
     printf("Factorial of %d is: %ld\n", 5, factorial(5));
return 0;
}


#endif // ALGO_H_
