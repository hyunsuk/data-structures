#include <stdio.h>
#include <stdlib.h>
#include "lib/common.h"
#include "lib/array.h"
#include "lib/recursive.h"

int main(void) {
    const int Factorials = 20;

    for (int i = 0; i < Factorials; i++) {
        printf("%d! = %ld\n", i + 1, Factorial(i + 1));
    }

    const int FibonacchiSeq = 20;

    for (int i = 0; i <= FibonacchiSeq; i++) {
        if (i != FibonacchiSeq) {
            printf("%d ", Fibonacchi(i + 1));
        } else {
            printf("%d\n", Fibonacchi(i + 1));
        }
    }

    const int alloc_length = 50;
    int *alloc_list = malloc((sizeof(int) * alloc_length));

    for (int i = 0; i < alloc_length; i++) {
        alloc_list[i] = i + 1;
    }

    int idx;
    idx = RecursiveBsearch(alloc_list, 0, alloc_length, 2);
    PrintValue(alloc_list, idx);
    free(alloc_list);

    HanoiTowerMove(4, 'A', 'B', 'C');

    return 0;
}
