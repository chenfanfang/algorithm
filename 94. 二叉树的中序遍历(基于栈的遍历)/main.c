//
//  main.c
//  94. 二叉树的中序遍历(基于栈的遍历)
//
//  Created by chenfanfang on 2019/8/26.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

/*
 给定一个二叉树，返回它的中序 遍历。
 
 示例:
 
 输入: [1,null,2,3]
 1
 \
 2
 /
 3
 
 输出: [1,3,2]
 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <stdio.h>
#include "BinarySearchTreeTool.h"

int *intValues;
int capacity = 0;
int indexFlag = 0;


//判断栈控件是否足够
void judgeIntValuesIsCapacityEnouth() {
    
    if (capacity == 0) { //初始化
        capacity = 10;
        intValues = calloc(capacity, sizeof(int));
    }
    
    int old_capacity = capacity;
    if (indexFlag >= capacity) {
        capacity = capacity * 1.5;
    }
    int *old_intValues = intValues;
    intValues = calloc(capacity, sizeof(int));
    for (int i = 0; i < old_capacity; i++) {
        intValues[i] = old_intValues[i];
    }
    
    free(old_intValues);
    
}

//解题思路、同递归有点类似。但是使用的辅助工具是栈
int *inorderTraversal(struct TreeNode* root, int* returnSize){
    TreeNode *node = root;
    
    
    return NULL;
}

int main(int argc, const char * argv[]) {
    
    int intValues[] = {34, 56, 29, 16, 18, 42, 3, 55, 19};
    BinarySearchTree *tree = createBinarySearchTree(intValues, 9);
    TreeNode *root = tree->root;
    int returnSize = 0;
    int *arr = inorderTraversal(root, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d  ",arr[i]);
    }
    return 0;
}
