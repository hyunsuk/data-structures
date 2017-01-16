#include <stdio.h>
#include "lib/linked_list.h"

int main(void)
{
    linked_list list;
    int data;
    list_init(&list);

    list_insert(&list, 11);
    list_insert(&list, 11);
    list_insert(&list, 22);
    list_insert(&list, 22);
    list_insert(&list, 33);

    printf("linked list length %d \n", list_count(&list));

    if (list_first(&list, &data)) {
        printf("%d ", data);
        while (list_next(&list, &data)) {
            printf("%d ", data);
        }
        printf("\n");
    }

    if (list_first(&list, &data)) {
        if (data == 22) {
            list_remove(&list);
        }
        while (list_next(&list, &data)) {
            if (data == 22) {
                list_remove(&list);
            }
        }
    }

    printf("current linked list length %d \n", list_count(&list));

    if (list_first(&list, &data)) {
        printf("%d ", data);
        while (list_next(&list, &data)) {
            printf("%d ", data);
        }
        printf("\n");
    }

    return 0;
}
