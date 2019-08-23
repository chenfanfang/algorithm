//
//  BinarySearchTreeTool.c
//  算法
//
//  Created by chenfanfang on 2019/8/22.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#include "BinarySearchTreeTool.h"


//创建树节点
TreeNode *createTreeNode(int val) {
    
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->parrent = NULL;
    return node;
}

TreeNode *getTreeNode(BinarySearchTree *tree ,int val) {
    
    int compareResult = 0;
    TreeNode *node = tree->root;
    while (node != NULL) {
        compareResult = val - node->val;
        if (compareResult == 0) {
            return node;
        }
        else if (compareResult > 0) {
            node = node->right;
        }
        else {
            node = node->left;
        }
    }
    return NULL;
}

//创建二叉搜索树， count 为intValues数组的长度
BinarySearchTree *createBinarySearchTree(int intValues[], int count) {
    BinarySearchTree *tree = calloc(1, sizeof(BinarySearchTree));
    for (int i = 0; i < count; i++) {
        treeAdd(tree, intValues[i]);
    }
    return tree;
}

int treeSize(BinarySearchTree *tree) {
    return tree->size;
}

bool treeIsEmpty(BinarySearchTree *tree) {
    return tree->size == 0;
}

//未实现
void treeClear(BinarySearchTree *tree) {
  
}

void treeAdd(BinarySearchTree *tree, int val) {
    
    TreeNode *newNode = createTreeNode(val);
    //添加第一个节点
    if (tree->root == NULL) {
        tree->root = newNode;
        tree->size ++;
        return;
    }
    
    TreeNode *parrentNode = NULL;
    TreeNode *node = tree->root;
    int compareResult = 0; //新加的节点若等于比较的节点 ，则为0， 若大于则为1  若小于 则为-1
    do {
        compareResult = val - node->val;
        parrentNode = node;
        if (compareResult > 0) {
            node = node->right;
        }
        else if (compareResult < 0) {
            node = node->left;
            
        } else {
            node->val = val;
            return;
        }
        
    } while (node != NULL);
    
    
    if (compareResult > 0) {
        parrentNode->right = newNode;
        newNode->parrent = parrentNode;
    }
    else {
        parrentNode->left = newNode;
        newNode->parrent = parrentNode;
    }
    
}


//未实现
void treeRemove(BinarySearchTree *tree) {
    
}

bool treeContains(BinarySearchTree *tree, int val) {
    TreeNode *treeNode = getTreeNode(tree, val);
    return treeNode != NULL;
}



