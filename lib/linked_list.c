#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void list_init(linked_list *list)
{
    list->head = (node*)malloc(sizeof(node));
    list->head->next = NULL;
    list->comp = NULL;
    list->num_of_data = 0;
}

void f_insert(linked_list *list, list_data data)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;

    new_node->next = list->head->next;
    list->head->next = new_node;

    list->num_of_data++;
}

void sorted_insert(linked_list *list, list_data data)
{
    node *new_node = (node*)malloc(sizeof(node));
    node *pred = list->head;
    new_node->data = data;

    while (pred->next != NULL && 0 != list->comp(data, pred->next->data)) {
        pred = pred->next;
    }
    new_node->next = pred->next;
    pred->next = new_node;
    list->num_of_data++;
}

void list_insert(linked_list *list, list_data data)
{
    if (list->comp == NULL) {
        f_insert(list, data);
    } else {
        sorted_insert(list, data);
    }
}

int list_first(linked_list *list, list_data *data)
{
    if (list->head->next == NULL) {
        return FALSE;
    }

    list->before = list->head;
    list->cur = list->head->next;

    *data = list->cur->data;
    return TRUE;
}

int list_next(linked_list *list, list_data *data)
{
    if (list->cur->next == NULL) {
        return FALSE;
    }

    list->before = list->cur;
    list->cur = list->cur->next;

    *data = list->cur->data;
    return TRUE;
}

list_data list_remove(linked_list *list)
{
    node *pos = list->cur;
    list_data data = pos->data;

    list->before->next = list->cur->next;
    list->cur = list->before;

    free(pos);
    list->num_of_data--;
    return data;
}

int list_count(linked_list *list)
{
    return list->num_of_data;
}

void set_sort_rule(linked_list *list, int (*comp)(list_data d1, list_data d2))
{
    list->comp = comp;
}
