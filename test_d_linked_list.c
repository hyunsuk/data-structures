#include <stdio.h>
#include "lib/common.h"
#include "lib/d_linked_list.h"

int main(void)
{
    DoublyLinkedList list;
    NodeData data;

    Init(&list);

    Append(&list, 1);
    Append(&list, 2);
    Append(&list, 3);
    Append(&list, 4);
    Append(&list, 5);
    Append(&list, 6);
    Append(&list, 7);
    Append(&list, 8);

    if (First(&list, &data)) {
        printf("%d ", data);

        while (Next(&list, &data)) {
            printf("%d ", data);
        }
        while (Prev(&list, &data)) {
            printf("%d ", data);
        }
        printf("\n");
    }

    if (First(&list, &data)) {
       if (data % 2 == 0) {
            Remove(&list);
        }
        while (Next(&list, &data)) {
            if (data % 2 == 0) {
                Remove(&list);
            }
        }
    }

    if (First(&list, &data)) {
        printf("%d ", data);

        while (Next(&list, &data)) {
            printf("%d ", data);
        }
        while (Prev(&list, &data)) {
            printf("%d ", data);
        }
        printf("\n");
    }

    return 0;
}
