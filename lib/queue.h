#ifndef LIB_QUEUE_H_
#define LIB_QUEUE_H_

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

void QueueInit(Queue *pq);
int QueueIsEmpty(Queue *pq);

void Enqueue(Queue *pq, NodeData data);
NodeData Dequeue(Queue *pq);
NodeData Peek(Queue *pq);

#endif
