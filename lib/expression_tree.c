#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "binary_tree.h"
#include "expression_tree.h"

void StackInit(Stack *stack) {
    stack->head = NULL;
}

int StackIsEmpty(Stack *stack) {
    if (stack->head == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void StackPush(Stack *stack, BTreeNode *data) {
    StackNode *new_node = (StackNode *) malloc(sizeof(StackNode));
    new_node->data = data;

    new_node->next = stack->head;
    stack->head = new_node;
}

BTreeNode * StackPop(Stack *stack) {
    if (StackIsEmpty(stack)) {
        printf("stack is empty");
        exit(-1);
    }

    StackNode *target = stack->head;
    BTreeNode *data = stack->head->data;
    stack->head = stack->head->next;

    free(target);
    return data;
}

BTreeNode * StackPeek(Stack *stack) {
    if (StackIsEmpty(stack)) {
        printf("stack is empty");
        exit(-1);
    }

    return stack->head->data;
}

BTreeNode * NewExpTree(char exp[]) {
    Stack stack;
    BTreeNode *exp_node;

    int exp_len = strlen(exp);

    StackInit(&stack);

    for (int i = 0; i < exp_len; i++) {
       exp_node = NewBTreeNode();

       if(isdigit(exp[i])) {
           SetBTreeData(exp_node, exp[i] - '0');
       } else {
           AppendRightSubTreeNode(exp_node, StackPop(&stack));
           AppendLeftSubTreeNode(exp_node, StackPop(&stack));
           SetBTreeData(exp_node, exp[i]);
       }

       StackPush(&stack, exp_node);
    }
    return StackPop(&stack);
}

int EvaluateExpTree(BTreeNode *bt) {
    int op1, op2;
    if(GetLeftSubTreeNode(bt) == NULL && GetRightSubTreeNode(bt) == NULL) {
        return GetBTreeData(bt);
    }

    op1 = EvaluateExpTree(GetLeftSubTreeNode(bt));
    op2 = EvaluateExpTree(GetRightSubTreeNode(bt));

    switch (GetBTreeData(bt)) {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
    }
    return 0;
}

void ShowTreeNodeData(int data) {
    if(0 <= data && data <= 9) {
        printf("%d ", data);
    } else {
        printf("%c ", data);
    }
}

void ShowPrefixTypeExp(BTreeNode *bt) {
    PreorderTraverse(bt, ShowTreeNodeData);
}
void ShowInfixTypeExp(BTreeNode *bt) {
    InorderTraverse(bt, ShowTreeNodeData);
}
void ShowPostfixTypeExp(BTreeNode *bt) {
    PostorderTraverse(bt, ShowTreeNodeData);
}


