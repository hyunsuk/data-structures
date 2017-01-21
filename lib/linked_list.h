#ifndef LIB_LINKED_LIST_H_
#define LIB_LINKED_LIST_H_

void Init(LinkedList *list);
void Append(LinkedList *list, NodeData data);
int Len(LinkedList *list);

int First(LinkedList *list, NodeData *data);
int Next(LinkedList *list, NodeData *data);

NodeData Remove(LinkedList *list);

void set_comp_func(LinkedList *list, int (*comp)(NodeData d1, NodeData d2));

#endif
