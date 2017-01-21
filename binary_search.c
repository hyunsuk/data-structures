#include <stdio.h>
#include <stdlib.h>
#include "lib/array.h"

int main(void) {
    int sorted_list[] = {1, 2, 4, 8, 16, 32, 64, 128, 512, 1024};
    int idx;

    idx = BsearchArray(sorted_list, ARRAY_LENGTH(sorted_list), 2);
    PrintValue(sorted_list, idx);
    printf("\n");

    idx = BsearchArray(sorted_list, ARRAY_LENGTH(sorted_list), 3);
    PrintValue(sorted_list, idx);
    printf("\n");

    idx = BsearchArray(sorted_list, ARRAY_LENGTH(sorted_list), 128);
    PrintValue(sorted_list, idx);
    printf("\n");

    const int kAllocLength = 100;
    int *alloc_list = malloc((sizeof(int) * kAllocLength));

    for (int i = 0; i < kAllocLength; i++) {
        alloc_list[i] = i + 1;
    }

    idx = BsearchArray(alloc_list, kAllocLength, 15);
    PrintValue(alloc_list, idx);
    free(alloc_list);

    return 0;
}
