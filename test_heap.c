#include <stdio.h>
#include "lib/heap.h"

int DataPriorityCompare(char ch1, char ch2) {
    return ch2 - ch1;
}

int main(void) {
    Heap heap;
    HeapInit(&heap, DataPriorityCompare);
    HeapInsert(&heap, 'a');
    HeapInsert(&heap, 'b');
    HeapInsert(&heap, 'c');
    HeapInsert(&heap, 'A');
    HeapInsert(&heap, 'B');
    HeapInsert(&heap, 'C');
    printf("delete %c \n", HeapDelete(&heap));

    HeapInsert(&heap, 'C');
    HeapInsert(&heap, 'B');
    HeapInsert(&heap, 'A');
    printf("delete %c \n", HeapDelete(&heap));

    while(!HeapIsEmpty(&heap)) {
        printf("while delete %c \n", HeapDelete(&heap));
    }

    return 0;
}
