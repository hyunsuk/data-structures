#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"

void QueueInit(Queue *pq) {
    pq->front = NULL;
    pq->rear = NULL;
}

int QueueIsEmpty(Queue *pq) {
    if(pq->front == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void Enqueue(Queue *pq, NodeData data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->data = data;

    if(QueueIsEmpty(pq)) {
        pq->front = new_node;
        pq->rear = new_node;
    } else {
        pq->rear->next = new_node;
        pq->rear = new_node;
    }
}

NodeData Dequeue(Queue *pq) {
    Node *delete_node;
    NodeData return_data;
    if(QueueIsEmpty(pq)) {
        printf("queue is empty\n");
        exit(-1);
    }

    delete_node = pq->front;
    return_data = delete_node->data;
    pq->front = pq->front->next;

    free(delete_node);
    return return_data;
}

NodeData Peek(Queue *pq) {
    if(QueueIsEmpty(pq)) {
        printf("queue is empty\n");
        exit(-1);
    }
    return pq->front->data;}
