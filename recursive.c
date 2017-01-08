#include <stdio.h>
#include <stdlib.h>
#include "lib/array.h"
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

    const int alloc_length = 50;
    int *alloc_list = malloc((sizeof(int) * alloc_length));

    for (int i = 0; i < alloc_length; i++) {
        alloc_list[i] = i + 1;
    }

    int idx;
    idx = recursive_binary_search(alloc_list, 0, alloc_length, 2);
    print_array_by_idx(alloc_list, idx);
    free(alloc_list);

    hanoi_tower_move(4, 'A', 'B', 'C');

    return 0;
}
