#include <stdio.h>
#include "lib/linked_list.h"

int who_is_precede(int d1, int d2)
{
    if (d1 < d2) {
        return 0;
    } else {
        return 1;
    }
}

int main(void)
{
    linked_list list;
    linked_list sorted_list;
    int data;

    list_init(&list);
    list_init(&sorted_list);

    set_sort_rule(&sorted_list, who_is_precede);

    list_insert(&list, 11);
    list_insert(&list, 11);
    list_insert(&list, 22);
    list_insert(&list, 22);
    list_insert(&list, 33);

    list_insert(&sorted_list, 11);
    list_insert(&sorted_list, 11);
    list_insert(&sorted_list, 22);
    list_insert(&sorted_list, 22);
    list_insert(&sorted_list, 33);

    printf("linked list length %d \n", list_count(&list));
    printf("sorted linked list length %d \n", list_count(&sorted_list));

    if (list_first(&list, &data)) {
        printf("%d ", data);
        while (list_next(&list, &data)) {
            printf("%d ", data);
        }
        printf("\n");
    }

    if (list_first(&sorted_list, &data)) {
        printf("%d ", data);
        while (list_next(&sorted_list, &data)) {
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
