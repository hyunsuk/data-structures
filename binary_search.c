#include <stdio.h>
#define ARRAY_LENGTH(x)  (sizeof(x) / sizeof(*x))

void print_sorted_list(int sorted_list[], int start_idx, int end_idx);

int get_target_index(int sorted_list[], int sorted_list_length, int target)
{
    int start_idx = 0;
    int end_idx = sorted_list_length - 1;
    int seek;

    printf("target: %d\n", target);

    while (start_idx <= end_idx) {
        print_sorted_list(sorted_list, start_idx, end_idx);
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

void print_sorted_list(int sorted_list[], int start_idx, int end_idx) {
    int i;
    for (i = start_idx; i < end_idx + 1; i++) {
        if (i == start_idx) {
            printf("{%d", sorted_list[i]);
        } else if ( i == end_idx) {
            printf(", %d}\n", sorted_list[i]);
        } else {
            printf(", %d", sorted_list[i]);
        }
    }
}

void print_search_result(int index, int sorted_list[])
{
    if (index == -1) {
        printf("not found\n");
    } else {
        printf("number %d is here: index %d\n", sorted_list[index], index);
    }
}

int main(void)
{
    int sorted_list[] = {1, 2, 4, 8, 16, 32, 64, 128, 512, 1024};
    int idx;

    idx = get_target_index(sorted_list, ARRAY_LENGTH(sorted_list), 2);
    print_search_result(idx, sorted_list);
    printf("\n");

    idx = get_target_index(sorted_list, ARRAY_LENGTH(sorted_list), 3);
    print_search_result(idx, sorted_list);
    printf("\n");

    idx = get_target_index(sorted_list, ARRAY_LENGTH(sorted_list), 128);
    print_search_result(idx, sorted_list);

    return 0;
}
