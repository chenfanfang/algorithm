//
//  main.c
//  94. 二叉树的中序遍历
//
//  Created by chenfanfang on 2019/8/22.
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

int intValuesSize = 10;

int *intValues;

//判断是否需要扩充数组数量
void judegeIfNeedReSizeArr(int currentSize) {
    //数组容量是否足够，不够，就重新开辟新的空间
    if (intValuesSize < currentSize) {
        int oldSize = intValuesSize;
        intValuesSize = intValuesSize * 1.5;
        int *newIntValues = calloc(intValuesSize, sizeof(int));
        for (int i = 0; i < oldSize; i++) {
            newIntValues[i] = intValues[i];
        }
        free(intValues);
        intValues = newIntValues;
    }
}


void traverse(struct TreeNode *node, int *returnSize){
    
    
    //=====================================================================后序遍历
  
     
    if (node == NULL) {
        return;
    }
     
    traverse(node->left, returnSize);
    traverse(node->right, returnSize);
    
    *returnSize = *returnSize + 1;
    judegeIfNeedReSizeArr(*returnSize);
    intValues[*returnSize - 1] = node->val;
 
    
    
    //=====================================================================前序遍历
    
    /*
     
    if (node == NULL) {
        return;
    }
    *returnSize = *returnSize + 1;
    judegeIfNeedReSizeArr(*returnSize);
    intValues[*returnSize - 1] = node->val;
    
    traverse(node->left, returnSize);
    traverse(node->right, returnSize);
     */
     
    
    //=====================================================================中序遍历
    /*
    if (node == NULL) {
        return;
    }
     
    traverse(node->left, returnSize);
    
    *returnSize = *returnSize + 1;
    judegeIfNeedReSizeArr(*returnSize);
    intValues[*returnSize - 1] = node->val;
    
    traverse(node->right, returnSize);
     */
}

int *traversalMain(struct TreeNode *root, int *returnSize){
    intValues = calloc(intValuesSize, sizeof(int));
    
    int size = 0;
    traverse(root, &size);
    *returnSize = size;
    return intValues;
}



int main(int argc, const char * argv[]) {
    int intValues[] = {59, 78, 98, 95, 13, 97, 80, 67, 81, 48, 70, 76, 25, 74, 58, 64, 22, 47, 63, 28, 17, 84, 52, 32, 50};
    BinarySearchTree *tree = createBinarySearchTree(intValues, 25);
    TreeNode *rootNode = tree->root;
    int *returnSize = malloc(sizeof(int));
    int *arr = traversalMain(rootNode, returnSize);
    
    printf("\n\n");
    for (int i = 0; i < *returnSize; i++) {
        printf("%d  ",arr[i]);
    }
    
    printf("\n\nreturnSize:%d",*returnSize);
    
    
    return 0;
}
