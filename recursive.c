#include <stdio.h>
#include "lib/recursive.h"

int main(void)
{
    const int factorials = 20;

    for (int i = 0; i < factorials; i++) {
        printf("%d! = %ld\n", i + 1, factorial(i + 1));
    }

    const int fibonacchi_seq = 20;

    for (int i = 0; i <= fibonacchi_seq; i++) {
        if (i != fibonacchi_seq) {
            printf("%d ", fibonacchi(i + 1));
        } else {
            printf("%d\n", fibonacchi(i + 1));
        }
    }
}
