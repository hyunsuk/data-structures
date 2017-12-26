#include <stdio.h>
#include "lib/common.h"
#include "lib/array.h"

int main(void) {
    CircularQueue queue;
    CircularQueueInit(&queue);

    EnqueueByCircular(&queue, 1);
    EnqueueByCircular(&queue, 2);
    EnqueueByCircular(&queue, 3);
    EnqueueByCircular(&queue, 4);
    EnqueueByCircular(&queue, 5);

    while(!CircularQueueIsEmpty(&queue)) {
        printf("%d ", DequeueByCircular(&queue));
    }
    return 0;
}
