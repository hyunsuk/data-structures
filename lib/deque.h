#ifndef LIB_DEQUE_H_
#define LIB_DEQUE_H_

typedef struct Deque {
    Node *head;
    Node *tail;
} Deque;

void DequeInit(Deque *pdq);
int DequeIsEmpty(Deque *pdq);

void DequeAppend(Deque *pdq, NodeData data);
void DequeAppendLeft(Deque *pdq, NodeData data);

NodeData DequePop(Deque *pdq);
NodeData DequePopLeft(Deque *pdq);

NodeData GetDequeLast(Deque *pdq);
NodeData GetDequeFirst(Deque *pdq);

#endif
