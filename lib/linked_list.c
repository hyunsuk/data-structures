#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "linked_list.h"

void Init(LinkedList *list) {
    // Dummy
    list->head = (Node *) malloc(sizeof(Node));
    list->head->next = NULL;

    list->comp = NULL;
    list->length = 0;
}

void insert(LinkedList *list, NodeData data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;

    new_node->next = list->head->next;
    list->head->next = new_node;

    list->length++;
}

void sorted_insert(LinkedList *list, NodeData data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    Node *competitor = list->head;
    new_node->data = data;

    while (competitor->next != NULL &&
           list->comp(data, competitor->next->data) != 0) {
        competitor = competitor->next;
    }
    new_node->next = competitor->next;
    competitor->next = new_node;
    list->length++;
}

void Append(LinkedList *list, NodeData data) {
    if (list->comp == NULL) {
        insert(list, data);
    } else {
        sorted_insert(list, data);
    }
}

int Len(LinkedList *list) {
    return list->length;
}

int First(LinkedList *list, NodeData *data) {
    if (list->head->next == NULL) {
        return FALSE;
    }

    // Always start next of dummy
    list->before = list->head;
    list->current = list->head->next;

    *data = list->current->data;
    return TRUE;
}

int Next(LinkedList *list, NodeData *data) {
    if (list->current->next == NULL) {
        return FALSE;
    }

    list->before = list->current;
    list->current = list->current->next;

    *data = list->current->data;
    return TRUE;
}

NodeData Remove(LinkedList *list) {
    Node *target = list->current;
    NodeData data = target->data;

    list->before->next = list->current->next;
    list->current = list->before;

    free(target);
    list->length--;
    return data;
}

void set_comp_func(LinkedList *list, int (*comp)(NodeData d1, NodeData d2)) {
    list->comp = comp;
}
