#ifndef LIB_LINKED_LIST_H_
#define LIB_LINKED_LIST_H_

#define TRUE 1
#define FALSE 0

typedef int NodeData;

typedef struct Node {
    NodeData data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *current;
    Node *before;
    int length;
    int (*comp)(NodeData d1, NodeData d2);
} LinkedList;

void Init(LinkedList *list);
void Append(LinkedList *list, NodeData data);
int Len(LinkedList *list);

int First(LinkedList *list, NodeData *data);
int Next(LinkedList *list, NodeData *data);

NodeData Remove(LinkedList *list);

void set_comp_func(LinkedList *list, int (*comp)(NodeData d1, NodeData d2));

#endif
