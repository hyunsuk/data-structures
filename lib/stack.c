#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "stack.h"

void Init(Stack *stack) {
    stack->head = NULL;
}

int IsEmpty(Stack *stack) {
    if (stack->head == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void Push(Stack *stack, StackData data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;

    new_node->next = stack->head;
    stack->head = new_node;
}

StackData Pop(Stack *stack) {
    if (IsEmpty(stack)) {
        return -1;
    }

    Node *target = stack->head;
    StackData data = stack->head->data;
    stack->head = stack->head->next;

    free(target);
    return data;
}

StackData Peek(Stack *stack) {
    if (IsEmpty(stack)) {
        return -1;
    }

    return stack->head->data;
}
