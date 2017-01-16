#ifndef __LIB_LINKED_LIST_H__
#define __LIB_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int list_data;

typedef struct _node
{
    list_data data;
    struct _node *next;
} node;

typedef struct _linked_list
{
    node *head;
    node *cur;
    node *before;
    int num_of_data;
    int (*comp)(list_data d1, list_data d2);
} linked_list;

void list_init(linked_list *list);
void list_insert(linked_list *list, list_data data);

int list_first(linked_list *list, list_data *data);
int list_next(linked_list *list, list_data *data);

list_data list_remove(linked_list *list);
int list_count(linked_list *list);

void set_sort_rule(linked_list *list, int (*comp)(list_data d1, list_data d2));

#endif
