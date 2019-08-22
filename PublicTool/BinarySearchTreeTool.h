//
//  BinarySearchTreeTool.h
//  算法
//
//  Created by chenfanfang on 2019/8/22.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#ifndef BinarySearchTreeTool_h
#define BinarySearchTreeTool_h

#include <stdio.h>
#include <stdbool.h>


// 二叉树节点结构体
typedef struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
} TreeNode;

// 二叉树
typedef struct BinarySearchTree {
    TreeNode *root;
} BinarySearchTree;

//创建二叉搜索树， count 为intValues数组的长度
BinarySearchTree *createBinarySearchTree(int intValues[], int count);

int treeSize(BinarySearchTree *tree);

bool treeIsEmpty(BinarySearchTree *tree);

void treeClear(BinarySearchTree *tree);

void treeAdd(BinarySearchTree *tree);

void treeRemove(BinarySearchTree *tree);

bool treeContains(BinarySearchTree *tree, TreeNode *node);


#endif /* BinarySearchTreeTool_h */
