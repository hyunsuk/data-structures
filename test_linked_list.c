#include <stdio.h>
#include "lib/linked_list.h"

int WhoIsPrecede(NodeData d1, NodeData d2) {
    if (d1 < d2) {
        return 0;
    } else {
        return 1;
    }
}

int main(void) {
    LinkedList list;
    LinkedList sorted_list;
    int data;

    Init(&list);
    Init(&sorted_list);

    set_comp_func(&sorted_list, WhoIsPrecede);

    Append(&list, 11);
    Append(&list, 11);
    Append(&list, 22);
    Append(&list, 22);
    Append(&list, 33);

    Append(&sorted_list, 11);
    Append(&sorted_list, 11);
    Append(&sorted_list, 22);
    Append(&sorted_list, 22);
    Append(&sorted_list, 33);

    printf("linked list length %d \n", Len(&list));
    printf("sorted linked list length %d \n", Len(&sorted_list));

    if (First(&list, &data)) {
        printf("%d ", data);
        while (Next(&list, &data)) {
            printf("%d ", data);
        }
        printf("\n");
    }

    if (First(&sorted_list, &data)) {
        printf("%d ", data);
        while (Next(&sorted_list, &data)) {
            printf("%d ", data);
        }
        printf("\n");
    }

    if (First(&list, &data)) {
        if (data == 22) {
            Remove(&list);
        }
        while (Next(&list, &data)) {
            if (data == 22) {
                Remove(&list);
            }
        }
    }

    printf("current linked list length %d \n", Len(&list));

    if (First(&list, &data)) {
        printf("%d ", data);
        while (Next(&list, &data)) {
            printf("%d ", data);
        }
        printf("\n");
    }

    return 0;
}
