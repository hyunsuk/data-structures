#ifndef __LIB_ARRAY_H__
#define __LIB_ARRAY_H__
#define ARRAY_LENGTH(x)  (sizeof(x) / sizeof(*x))

void print_array(int *array, int start_idx, int end_idx)
{
    if (start_idx >= end_idx) {
        return;
    }

    printf("{");
    for (int i = start_idx; i < end_idx; i++) {
       printf("%d, ", array[i]);
    }
    printf("\b\b}\n");
}

void print_array_by_idx(int *array, int index)
{
    if (index == -1) {
        printf("not found\n");
    } else {
        printf("number %d is here: index %d\n", array[index], index);
    }
}

int get_idx_by_val(int *sorted_list, int list_length, int target)
{
    int start_idx = 0;
    int end_idx = list_length - 1;
    int seek;

    printf("target: %d\n", target);

    while (start_idx <= end_idx) {
        print_array(sorted_list, start_idx, end_idx);
        printf("start idx: %d, end idx: %d\n", start_idx, end_idx);

        seek = (start_idx + end_idx) / 2;
        printf("so seek is now: %d\n", seek);

        if (target == sorted_list[seek]) {
            return seek;
        } else {
            if (target < sorted_list[seek]) {
                end_idx = seek - 1;
            } else {
                start_idx = seek + 1;
            }
        }
    }
    return -1;
}
#endif