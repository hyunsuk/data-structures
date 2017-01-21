#ifndef LIB_D_LINKED_LIST_H_
#define LIB_D_LINKED_LIST_H_

void Init(DoublyLinkedList *list);
void Append(DoublyLinkedList *list, NodeData data);
int Len(DoublyLinkedList *list);

int First(DoublyLinkedList *list, NodeData *data);
int Next(DoublyLinkedList *list, NodeData *data);
int Prev(DoublyLinkedList *list, NodeData *data);

NodeData Remove(DoublyLinkedList *list);

#endif
