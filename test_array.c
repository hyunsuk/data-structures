#include <stdio.h>
#include "lib/array.h"

int main(void) {
    ArrayList list;
    int data;
    Init(&list);

    Append(&list, 11);
    Append(&list, 11);
    Append(&list, 22);
    Append(&list, 22);
    Append(&list, 33);

    printf("list length %d \n", Len(&list));

    if (First(&list, &data)) {
        printf("%d ", data);
        while (Next(&list, &data)) {
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

    printf("current list length %d \n", Len(&list));

    if (First(&list, &data)) {
        printf("%d ", data);
        while (Next(&list, &data)) {
            printf("%d ", data);
        }
        printf("\n");
    }

    return 0;
}
