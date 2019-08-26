//
//  StackTool.c
//  算法
//
//  Created by chenfanfang on 2019/8/26.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#include "StackTool.h"

void freeNode(struct StackNode *node) {
    free(node);
}

//创建栈
Stack *stackCreate() {
    Stack *stack = calloc(1, sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}
//清空栈
void stackRemodeAll(Stack *stack) {
    struct StackNode *topNode = stack->top;
    struct StackNode *oldTopNode  = topNode;
    while (topNode != NULL) {
        oldTopNode = topNode;
        topNode = topNode->next;
        free(oldTopNode);
    }
    free(oldTopNode);
    stack->size = 0;
    stack->top = NULL;
}
//销毁栈
void stackDestory(Stack *stack) {
    stackRemodeAll(stack);
    free(stack);
}
//判空
int stackIsEmpty(Stack *stack) {
    return stack->size == 0;
}
//入栈
int stackPush(Stack *stack, int val) {
    stack->size = stack->size + 1;
    StackNode *newNode = calloc(1, sizeof(StackNode));
    newNode->data = val;
    
    newNode->next = stack->top;
    stack->top = newNode;
    return val;
    
}
//出栈 （若出栈错误，则返回-1）
int stackPop(Stack *stack) {
    if (stack->top == NULL) {
        return -1;
    }
    
    StackNode *topNode = stack->top;
    stack->top = topNode->next;
    unsigned int data = topNode->data;
    free(topNode);
    return data;
    
}
//取栈顶元素 （若取栈顶元素错误，则返回-1）
int GetTopElement(Stack *stack) {
    if (stack->top == NULL) {
        return -1;
    }
    
    unsigned int data = stack->top->data;
    return data;
}
