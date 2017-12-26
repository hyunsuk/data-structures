#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void PrintArray(int *array, int start_idx, int end_idx) {
    if (start_idx >= end_idx) {
        return;
    }

    printf("{");
    for (int i = start_idx; i < end_idx; i++) {
       printf("%d, ", array[i]);
    }
    printf("\b\b}\n");
}

void PrintValue(int *array, int index) {
    if (index == -1) {
        printf("not found\n");
    } else {
        printf("value %d is here: index %d\n", array[index], index);
    }
}

int BsearchArray(int *sorted_list, int list_length, int target) {
    int start_idx = 0;
    int end_idx = list_length - 1;
    int seek;

    printf("target: %d\n", target);

    while (start_idx <= end_idx) {
        PrintArray(sorted_list, start_idx, end_idx);
        printf("start idx: %d, end idx: %d\n", start_idx, end_idx);

        seek = (start_idx + end_idx) / 2;
        printf("so seek is now: %d\n", seek);

        if (target == sorted_list[seek]) {
            return seek;
        } else {
            if (target < sorted_list[seek]) {
                end_idx = seek - 1;
            } else {
                start_idx = seek + 1;
            }
        }
    }
    return -1;
}

void Init(ArrayList *list) {
    list->length = 0;
    list->current_position = -1;
}

void Append(ArrayList *list, ListData data) {
    if (list->length >= LIST_LEN) {
        puts("list is full");
        return;
    }
    list->arr[list->length] = data;
    list->length++;
}

int Len(ArrayList *list) {
    return list->length;
}

int First(ArrayList *list, ListData *data) {
    if (list->length == 0) {
        return FALSE;
    }
    list->current_position = 0;
    *data = list->arr[0];
    return TRUE;
}

int Next(ArrayList *list, ListData *data) {
    if (list->current_position >= list->length - 1) {
        return FALSE;
    }
    list->current_position++;
    *data = list->arr[list->current_position];
    return TRUE;
}

ListData Remove(ArrayList *list) {
    int pos = list->current_position;
    int num = list->length;
    ListData data = list->arr[pos];

    for (int i = pos; i < num - 1; i++) {
        list->arr[i] = list->arr[i + 1];
    }

    list->length--;
    list->current_position--;
    return data;
}

void StackInit(ArrayStack *stack) {
    stack->top = -1;
}

int IsEmpty(ArrayStack *stack) {
    if (stack->top == -1) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void Push(ArrayStack *stack, StackData data) {
    stack->top += 1;
    stack->arr[stack->top] = data;
}

StackData Pop(ArrayStack *stack) {
    if (IsEmpty(stack)) {
        return -1;
    }

    StackData data = stack->arr[stack->top];
    stack->top -= 1;
    return data;
}

StackData Peek(ArrayStack *stack) {
    if (IsEmpty(stack)) {
        return -1;
    }

    return stack->arr[stack->top];
}

void CircularQueueInit(CircularQueue *pq) {
    pq->front = 0;
    pq->rear = 0;
}

int CircularQueueIsEmpty(CircularQueue *pq) {
    if(pq->front == pq->rear) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int GetCircularQueueNextPositionIndex(int pos) {
    if(pos == QUEUE_LEN - 1) {
        return 0;
    } else {
        return pos + 1;
    }
}

void EnqueueByCircular(CircularQueue *pq, QueueData data) {
    if(GetCircularQueueNextPositionIndex(pq->rear) == pq->front) {
        printf("queue is full\n");
        exit(-1);
    }
    pq->rear = GetCircularQueueNextPositionIndex(pq->rear);
    pq->queueArray[pq->rear] = data;
}

QueueData DequeueByCircular(CircularQueue *pq) {
    if(CircularQueueIsEmpty(pq)) {
        printf("queue is empty\n");
        exit(-1);
    }

    pq->front = GetCircularQueueNextPositionIndex(pq->front);
    return pq->queueArray[pq->front];
}

QueueData CircularQueuePeek(CircularQueue *pq) {
    if(CircularQueueIsEmpty(pq)) {
        printf("queue is empty\n");
        exit(-1);
    }
    return pq->queueArray[GetCircularQueueNextPositionIndex(pq->front)];
}
