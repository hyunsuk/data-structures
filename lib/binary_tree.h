#ifndef LIB_BTREENODE_H_
#define LIB_BTREENODE_H_

typedef int BTreeData;

typedef struct _bTreeNode {
    BTreeData data;
    struct _bTreeNode *left;
    struct _bTreeNode *right;
} BTreeNode;

BTreeNode * NewBTreeNode(void);
BTreeData GetBTreeData(BTreeNode *bt_node);
void SetBTreeData(BTreeNode *bt_node, BTreeData data);

BTreeNode * GetLeftSubTreeNode(BTreeNode *bt_node);
BTreeNode * GetRightSubTreeNode(BTreeNode *bt_node);

void AppendLeftSubTreeNode(BTreeNode *main, BTreeNode *sub);
void AppendRightSubTreeNode(BTreeNode *main, BTreeNode *sub);

typedef void VisitFuncPtr(int data);

void PreorderTraverse(BTreeNode *bt_node, VisitFuncPtr callback);
void InorderTraverse(BTreeNode *bt_node, VisitFuncPtr callback);
void PostorderTraverse(BTreeNode *bt_node, VisitFuncPtr callback);

void DeleteBTree(BTreeNode *bt_node);

#endif
