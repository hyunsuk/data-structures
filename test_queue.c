#include <stdio.h>
#include "lib/common.h"
#include "lib/queue.h"

int main(void) {
    Queue queue;
    QueueInit(&queue);

    Enqueue(&queue, 1);
    Enqueue(&queue, 2);
    Enqueue(&queue, 3);
    Enqueue(&queue, 4);
    Enqueue(&queue, 5);

    while(!QueueIsEmpty(&queue)) {
        printf("%d ", Dequeue(&queue));
    }
    return 0;
}
