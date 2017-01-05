#include <stdio.h>
#include <stdlib.h>
#include "lib/array.h"

int main(void)
{
    int sorted_list[] = {1, 2, 4, 8, 16, 32, 64, 128, 512, 1024};
    int idx;

    idx = get_idx_by_val(sorted_list, ARRAY_LENGTH(sorted_list), 2);
    print_array_by_idx(sorted_list, idx);
    printf("\n");

    idx = get_idx_by_val(sorted_list, ARRAY_LENGTH(sorted_list), 3);
    print_array_by_idx(sorted_list, idx);
    printf("\n");

    idx = get_idx_by_val(sorted_list, ARRAY_LENGTH(sorted_list), 128);
    print_array_by_idx(sorted_list, idx);
    printf("\n");

    const int alloc_length = 100;
    int *alloc_list = malloc((sizeof(int) * alloc_length));

    for (int i = 0; i < alloc_length; i++) {
        alloc_list[i] = i + 1;
    }

    idx = get_idx_by_val(alloc_list, alloc_length, 15);
    print_array_by_idx(alloc_list, idx);
    free(alloc_list);

    return 0;
}
