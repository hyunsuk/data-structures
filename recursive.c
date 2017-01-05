#include <stdio.h>
#include "lib/recursive.h"

int main(void)
{
    const int factorials = 20;

    for (int i = 0; i < factorials; i++) {
        printf("%d! = %ld\n", i + 1, factorial(i + 1));
    }
}
