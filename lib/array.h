#ifndef __LIB_ARRAY_H__
#define __LIB_ARRAY_H__

#define TRUE 1
#define FALSE 0
#define ARRAY_LENGTH(x)  (sizeof(x) / sizeof(*x))

#define LIST_LEN 100
typedef int list_data;

typedef struct __array_list
{
    list_data arr[LIST_LEN];
    int num_of_data;
    int cur_pos;
} array_list;


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

void arr_list_init(array_list *list)
{
    list->num_of_data = 0;
    list->cur_pos = -1;
}

void arr_list_insert(array_list *list, list_data data)
{
    if (list->num_of_data >= LIST_LEN) {
        puts("list is full");
        return;
    }
    list->arr[list->num_of_data] = data;
    list->num_of_data++;
}

int arr_list_first(array_list *list, list_data *data)
{
    if (list->num_of_data == 0) {
        return FALSE;
    }
    list->cur_pos = 0;
    *data = list->arr[0];
    return TRUE;
}

int arr_list_next(array_list *list, list_data *data)
{
    if (list->cur_pos >= list->num_of_data - 1) {
        return FALSE;
    }
    list->cur_pos++;
    *data = list->arr[list->cur_pos];
    return TRUE;
}

int arr_list_remove(array_list *list)
{
    int pos = list->cur_pos;
    int num = list->num_of_data;
    int i;
    list_data data = list->arr[pos];

    for (i = pos; i < num - 1; i++) {
        list->arr[i] = list->arr[i + 1];
    }

    list->num_of_data--;
    list->cur_pos--;
    return data;
}

int arr_list_count(array_list *list)
{
    return list->num_of_data;
}
#endif