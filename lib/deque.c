#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "deque.h"

void DequeInit(Deque *pdq) {
    pdq->head = NULL;
    pdq->tail = NULL;
}

int DequeIsEmpty(Deque *pdq) {
    if(pdq->head == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
};

void DequeAppend(Deque *pdq, NodeData data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = pdq->tail;

    if(DequeIsEmpty(pdq)) {
        pdq->head = new_node;
    } else {
        pdq->tail->next = new_node;
    }

    new_node->next = NULL;
    pdq->tail = new_node;
}

void DequeAppendLeft(Deque *pdq, NodeData data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = pdq->head;

    if(DequeIsEmpty(pdq)) {
        pdq->tail = new_node;
    } else {
        pdq->head->prev = new_node;
    }

    new_node->prev = NULL;
    pdq->head = new_node;
}

NodeData DequePop(Deque *pdq) {
    Node *delete_node = pdq->tail;

    if(DequeIsEmpty(pdq)) {
        printf("deque is empty");
        exit(-1);
    }

    NodeData return_data = pdq->tail->data;
    pdq->tail = pdq->tail->prev;
    free(delete_node);

    if(pdq->tail == NULL) {
        pdq->head = NULL;
    } else {
        pdq->tail->next = NULL;
    }
    return return_data;
}

NodeData DequePopLeft(Deque *pdq) {
    Node *delete_node = pdq->head;

    if(DequeIsEmpty(pdq)) {
        printf("deque is empty");
        exit(-1);
    }

    NodeData return_data = pdq->head->data;
    pdq->head = pdq->head->next;
    free(delete_node);

    if(pdq->head == NULL) {
        pdq->tail = NULL;
    } else {
        pdq->head->prev = NULL;
    }
    return return_data;
}

NodeData GetDequeLast(Deque *pdq) {
    if(DequeIsEmpty(pdq)) {
        printf("deque is empty");
        exit(-1);
    }
    return pdq->tail->data;
}

NodeData DetDequeFirst(Deque *pdq) {
    if(DequeIsEmpty(pdq)) {
        printf("deque is empty");
        exit(-1);
    }
    return pdq->head->data;
}
