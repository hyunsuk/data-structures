#include <stdio.h>
#include "lib/array.h"

int main(void)
{
    array_list list;
    int data;
    arr_list_init(&list);

    arr_list_insert(&list, 11);
    arr_list_insert(&list, 11);
    arr_list_insert(&list, 22);
    arr_list_insert(&list, 22);
    arr_list_insert(&list, 33);

    printf("list length %d \n", arr_list_count(&list));

    if (arr_list_first(&list, &data)) {
        printf("%d ", data);
        while (arr_list_next(&list, &data)) {
            printf("%d ", data);
        }
        printf("\n");
    }

    if (arr_list_first(&list, &data)) {
        if (data == 22) {
            arr_list_remove(&list);
        }
        while (arr_list_next(&list, &data)) {
            if (data == 22) {
                arr_list_remove(&list);
            }
        }
    }

    printf("current list length %d \n", arr_list_count(&list));

    if (arr_list_first(&list, &data)) {
        printf("%d ", data);
        while (arr_list_next(&list, &data)) {
            printf("%d ", data);
        }
        printf("\n");
    }

    return 0;
}