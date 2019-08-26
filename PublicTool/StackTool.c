//
//  StackTool.c
//  算法
//
//  Created by chenfanfang on 2019/8/26.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#include "StackTool.h"

#include <assert.h>

void freeNode(struct StackNode *node) {
    free(node);
}

//创建栈
Stack *stackCreate(size_t dataSize) {
    Stack *stack = calloc(1, sizeof(Stack));
    stack->top = NULL;
    stack->length = 0;
    stack->dataSize = dataSize;
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
    stack->length = 0;
    stack->top = NULL;
}
//销毁栈
void stackDestory(Stack *stack) {
    stackRemodeAll(stack);
    free(stack);
}
//判空
bool stackIsEmpty(Stack *stack) {
    return stack->length == 0;
}
//入栈
void stackPush(Stack *stack, void *const value) {
    
    stack->length = stack->length + 1;
    StackNode *newNode = calloc(1, sizeof(StackNode));
    newNode->data = value;
    
    newNode->next = stack->top;
    stack->top = newNode;
    
}
//出栈 （若出栈错误，则返回-1）
void *stackPop(Stack *stack) {
    if (stack->top == NULL) {
        printf("栈中没有数据，无法pop");
        assert(false);
    }
    
    StackNode *topNode = stack->top;
    stack->top = topNode->next;
    void *data = topNode->data;
    free(topNode);
    return data;
    
}
//取栈顶元素 （若取栈顶元素错误，则返回-1）
void *getTopElement(Stack *stack) {
    if (stack->top == NULL) {
        printf("栈中没有数据，无法获取数据");
        assert(false);
    }
    
    void *data = stack->top->data;
    return data;
}
