#ifndef LIB_C_LINKED_LIST_H_
#define LIB_C_LINKED_LIST_H_

void Init(CircularLinkedList *list);
void Append(CircularLinkedList *list, NodeData data);
void InsertFront(CircularLinkedList *list, NodeData data);
int Len(CircularLinkedList *list);

int First(CircularLinkedList *list, NodeData *data);
int Next(CircularLinkedList *list, NodeData *data);

NodeData Remove(CircularLinkedList *list);

#endif
