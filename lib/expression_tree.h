#ifndef LIB_EXPRESSION_TREE_H_
#define LIB_EXPRESSION_TREE_H_

#define TRUE 1
#define FALSE 0

#include "binary_tree.h"

typedef BTreeNode * Data;

typedef struct StackNode {
    Data data;
    struct StackNode *next;
    struct StackNode *prev;
} StackNode;

typedef struct Stack {
    StackNode *head;
} Stack;

void StackInit(Stack *stack);
int StackIsEmpty(Stack *stack);

void StackPush(Stack *stack, BTreeNode *data);
BTreeNode * StackPop(Stack *stack);
BTreeNode * StackPeek(Stack *stack);

BTreeNode * NewExpTree(char exp[]);

int EvaluateExpTree(BTreeNode *bt);

void ShowPrefixTypeExp(BTreeNode *bt);
void ShowInfixTypeExp(BTreeNode *bt);
void ShowPostfixTypeExp(BTreeNode *bt);


#endif
