#ifndef LIB_STACK_H_
#define LIB_STACK_H_

void Init(Stack *stack);
int IsEmpty(Stack *stack);

void Push(Stack *stack, StackData data);
StackData Pop(Stack *stack);
StackData Peek(Stack *stack);

#endif
