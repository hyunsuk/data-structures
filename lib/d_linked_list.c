#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void Init(DoublyLinkedList *list) {
    // Dummy of head
    list->head = (Node *) malloc(sizeof(Node));
    list->head->prev = NULL;

    // Dummy of tail
    list->tail = (Node *) malloc(sizeof(Node));
    list->tail->next = NULL;

    list->head->next = list->tail;
    list->tail->prev = list->head;

    list->length = 0;
}

void Append(DoublyLinkedList *list, NodeData data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;

    new_node->prev = list->tail->prev;
    new_node->prev->next = new_node;

    new_node->next = list->tail;
    list->tail->prev = new_node;

    list->length++;
}

int Len(DoublyLinkedList *list) {
    return list->length;
}

int First(DoublyLinkedList *list, NodeData *data) {
    if (list->head->next == list->tail) {
        return FALSE;
    }

    list->current = list->head->next;
    *data = list->current->data;
    return TRUE;
}

int Next(DoublyLinkedList *list, NodeData *data) {
    if (list->current->next == list->tail) {
        return FALSE;
    }

    list->current = list->current->next;
    *data = list->current->data;
    return TRUE;
}

int Prev(DoublyLinkedList *list, NodeData *data) {
    if (list->current->prev == list->head) {
        return FALSE;
    }

    list->current = list->current->prev;
    *data = list->current->data;
    return TRUE;
}

NodeData Remove(DoublyLinkedList *list) {
    Node *target = list->current;
    NodeData data = list->current->data;

    list->current->prev->next = list->current->next;
    list->current->next->prev = list->current->prev;

    list->current = list->current->prev;

    free(target);
    list->length--;
    return data;
}
