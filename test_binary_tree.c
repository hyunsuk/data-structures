#include <stdio.h>
#include "lib/binary_tree.h"

void ShowBTreeData(int data);

int main(void) {

    BTreeNode *bt1 = NewBTreeNode();
    BTreeNode *bt2 = NewBTreeNode();
    BTreeNode *bt3 = NewBTreeNode();
    BTreeNode *bt4 = NewBTreeNode();
    BTreeNode *bt5 = NewBTreeNode();
    BTreeNode *bt6 = NewBTreeNode();

    SetBTreeData(bt1, 1);
    SetBTreeData(bt2, 2);
    SetBTreeData(bt3, 3);
    SetBTreeData(bt4, 4);
    SetBTreeData(bt5, 5);
    SetBTreeData(bt6, 6);

    AppendLeftSubTreeNode(bt1, bt2);
    AppendRightSubTreeNode(bt1, bt3);

    AppendLeftSubTreeNode(bt2, bt4);
    AppendRightSubTreeNode(bt2, bt5);

    AppendLeftSubTreeNode(bt3, bt6);

    PreorderTraverse(bt1, ShowBTreeData);
    printf("\n");

    InorderTraverse(bt1, ShowBTreeData);
    printf("\n");

    PostorderTraverse(bt1, ShowBTreeData);
    printf("\n");

    BTreeNode *bt7 = NewBTreeNode();
    SetBTreeData(bt7, 7);

    AppendLeftSubTreeNode(bt1, bt7);
    PreorderTraverse(bt1, ShowBTreeData);
    printf("\n");

    return 0;
}

void ShowBTreeData(int data) {
    printf("%d ", data);
}
