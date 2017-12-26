#include <stdio.h>
#include "lib/common.h"
#include "lib/deque.h"

int main(void) {
    Deque deque;
    DequeInit(&deque);

    DequeAppendLeft(&deque, 3);
    DequeAppendLeft(&deque, 2);
    DequeAppendLeft(&deque, 1);

    DequeAppend(&deque, 4);
    DequeAppend(&deque, 5);
    DequeAppend(&deque, 6);

    while(!DequeIsEmpty(&deque)) {
        printf("%d ", DequePopLeft(&deque));
    }
    printf("\n");

    DequeAppendLeft(&deque, 3);
    DequeAppendLeft(&deque, 2);
    DequeAppendLeft(&deque, 1);

    DequeAppend(&deque, 4);
    DequeAppend(&deque, 5);
    DequeAppend(&deque, 6);

    while(!DequeIsEmpty(&deque)) {
        printf("%d ", DequePop(&deque));
    }

    return 0;
}
