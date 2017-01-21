#ifndef LIB_COMMON_H_
#define LIB_COMMON_H_

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100
#define ARRAY_LENGTH(x)  (sizeof(x) / sizeof(*x))

typedef int ListData;

typedef struct ArrayList {
    ListData arr[LIST_LEN];
    int length;
    int current_position;
} ArrayList;

typedef int NodeData;

typedef struct Node {
    NodeData data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *current;
    Node *before;
    int length;
    int (*comp)(NodeData d1, NodeData d2);
} LinkedList;

typedef struct CircularLinkedList {
    Node *tail;
    Node *current;
    Node *before;
    int length;
} CircularLinkedList;

typedef struct DoublyLinkedList {
    Node *head;
    Node *tail;
    Node *current;
    int length;
} DoublyLinkedList;
#endif
