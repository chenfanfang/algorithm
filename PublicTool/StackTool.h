//
//  StackTool.h
//  算法
//
//  Created by chenfanfang on 2019/8/26.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

///////////////////////////////////////////////// C 语言模拟栈//////////////////////////////////////


#ifndef StackTool_h
#define StackTool_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct StackNode{
    void *data; //模拟的数据必须>=0
    struct StackNode *next;
} StackNode;

typedef struct Stack {
    int length; //栈中有多少个元素
    size_t dataSize; //StackNode中的data的 size  (sizeof)
    StackNode *top; //栈顶
    
} Stack; 
//创建栈
Stack *stackCreate(size_t dataSize);
//清空栈
void stackRemodeAll(Stack *stack);
//销毁栈
void stackDestory(Stack *stack);
//判空
bool stackIsEmpty(Stack *stack);
//入栈
void stackPush(Stack *stack, void *const value);
//出栈 
void *stackPop(Stack *stack);
//取栈顶元素
void *getTopElement(Stack *stack);

#endif /* StackTool_h */
