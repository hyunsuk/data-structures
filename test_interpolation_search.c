#include <stdio.h>

int InterpolationSearch(int sorted_list[], int start_idx, int end_idx, int target) {

    if (sorted_list[start_idx] > target || sorted_list[end_idx] < target) {
        return -1; // termination - not found
    }

    int seek = (
        (double)
        (target - sorted_list[start_idx])
        / (sorted_list[end_idx] - sorted_list[start_idx])
        * (end_idx - start_idx)
    ) + start_idx;

    if (target == sorted_list[seek]) {
        return seek; // termination - found
    } else if (target < sorted_list[seek]) {
        return InterpolationSearch(sorted_list, start_idx, seek -1, target);
    } else {
        return InterpolationSearch(sorted_list, seek + 1, end_idx, target);
    }
}

void PrintArray(int *array, int start_idx, int end_idx) {
    if (start_idx >= end_idx) {
        return;
    }

    printf("{");
    for (int i = start_idx; i < end_idx; i++) {
       printf("%d, ", array[i]);
    }
    printf("\b\b}\n");
}

int main(void) {
    int sorted_list[] = {1, 3, 5, 7, 9, 12};
    int idx;
    int target = 7;

    int sorted_list_length = sizeof(sorted_list) / sizeof(int);

    PrintArray(sorted_list, 0, sorted_list_length - 1);
    idx = InterpolationSearch(sorted_list, 0, sorted_list_length - 1, target);

    if(idx == -1) {
        printf("fail to search\n");
    } else {
        printf("target '%d' index is '%d'\n", target, idx);
    }

    target = 10;

    idx = InterpolationSearch(sorted_list, 0, sorted_list_length - 1, target);

    if(idx == -1) {
        printf("target '%d' search failed\n", target);
    } else {
        printf("target '%d' index is '%d'\n", target, idx);
    }

    return 0;
}
