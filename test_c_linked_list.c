#include <stdio.h>
#include "lib/common.h"
#include "lib/c_linked_list.h"

int main(void)
{
    CircularLinkedList list;
    NodeData data;
    int i, list_len = 0;

    Init(&list);

    Append(&list, 3);
    Append(&list, 4);
    Append(&list, 5);

    InsertFront(&list, 2);
    InsertFront(&list, 1);

    if (First(&list, &data)) {
        printf("%d ", data);

        for (i = 0; i < Len(&list) * 3 - 1; i++) {
            if (Next(&list, &data)) {
                printf("%d ", data);
            }
        }
    }
    printf("\n");

    list_len = Len(&list);

    if (list_len != 0) {
        First(&list, &data);

        if (data % 2 == 0) {
            Remove(&list);
        }

        for (i = 0; i < list_len - 1; i++) {
            Next(&list, &data);
            if (data % 2 == 0) {
                Remove(&list);
            }
        }
    }

    if (First(&list, &data)) {
        printf("%d ", data);

        for (i = 0; i < Len(&list) - 1; i++) {
            if (Next(&list, &data)) {
                printf("%d ", data);
            }
        }
    }
    printf("\n");

    return 0;
}
