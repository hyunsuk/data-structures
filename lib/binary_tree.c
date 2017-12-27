#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "binary_tree.h"

BTreeNode * NewBTreeNode(void) {
    BTreeNode *bt_node = (BTreeNode*) malloc(sizeof(BTreeNode));
    bt_node->left = NULL;
    bt_node->right = NULL;
    return bt_node;
}

BTreeData GetBTreeData(BTreeNode *bt_node) {
    return bt_node->data;
}

void SetBTreeData(BTreeNode *bt_node, BTreeData data) {
    bt_node->data = data;
}

BTreeNode * GetLeftSubTreeNode(BTreeNode *bt_node) {
    return bt_node->left;
}

BTreeNode * GetRightSubTreeNode(BTreeNode *bt_node) {
    return bt_node->right;
}

void AppendLeftSubTreeNode(BTreeNode *main, BTreeNode *sub) {
    if(main->left != NULL) {
        DeleteBTree(main->left);
    }
    main->left = sub;
}

void AppendRightSubTreeNode(BTreeNode *main, BTreeNode *sub) {
    if(main->right != NULL) {
        DeleteBTree(main->right);
    }
    main->right = sub;
}

void PreorderTraverse(BTreeNode *bt_node, VisitFuncPtr callback) {
    if(bt_node == NULL) {
        return ;
    }
    callback(bt_node->data);
    PreorderTraverse(bt_node->left, callback);
    PreorderTraverse(bt_node->right, callback);
}

void InorderTraverse(BTreeNode *bt_node, VisitFuncPtr callback) {
    if(bt_node == NULL) {
        return ;
    }
    InorderTraverse(bt_node->left, callback);
    callback(bt_node->data);
    InorderTraverse(bt_node->right, callback);
}

void PostorderTraverse(BTreeNode *bt_node, VisitFuncPtr callback) {
    if(bt_node == NULL) {
        return ;
    }
    PostorderTraverse(bt_node->left, callback);
    PostorderTraverse(bt_node->right, callback);
    callback(bt_node->data);
}

void DeleteBTree(BTreeNode *bt_node) {
    if(bt_node == NULL) {
        return ;
    }
    DeleteBTree(bt_node->left);
    DeleteBTree(bt_node->right);
    free(bt_node);
}
