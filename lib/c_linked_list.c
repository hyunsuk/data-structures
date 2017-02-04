#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void Init(CircularLinkedList *list) {
    list->tail = NULL;
    list->current = NULL;
    list->before = NULL;
    list->length = 0;
}

void Append(CircularLinkedList *list, NodeData data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;

    if (list->tail == NULL) {
        list->tail = new_node;
        new_node->next = new_node;
    } else {
        new_node->next = list->tail->next;
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->length++;
}

void InsertFront(CircularLinkedList *list, NodeData data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;

    if (list->tail == NULL) {
        list->tail = new_node;
        new_node->next = new_node;
    } else {
        new_node->next = list->tail->next;
        list->tail->next = new_node;
    }

    list->length++;
}

int Len(CircularLinkedList *list) {
    return list->length;
}

int First(CircularLinkedList *list, NodeData *data) {
    if (list->tail == NULL) {
        return FALSE;
    }

    list->before = list->tail;
    list->current = list->tail->next;

    *data = list->current->data;
    return TRUE;
}

int Next(CircularLinkedList *list, NodeData *data) {
    if (list->tail == NULL) {
        return FALSE;
    }

    list->before = list->current;
    list->current = list->current->next;

    *data = list->current->data;
    return TRUE;
}

NodeData Remove(CircularLinkedList *list) {
    Node *target = list->current;
    NodeData data = target->data;

    if (target == list->tail) {
        if (list->tail == list->tail->next) {
            list->tail = NULL;
        } else {
            list->tail = list->before;
        }
    }

    list->before->next = list->current->next;
    list->current = list->before;

    free(target);
    list->length--;
    return data;
}
