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


typedef struct StackNode{
    unsigned int data; //模拟的数据必须>=0
    struct StackNode *next;
} StackNode;

typedef struct Stack {
    int size;
    StackNode *top; //栈顶
    
} Stack;
//创建栈
Stack *stackCreate();
//清空栈
void stackRemodeAll(Stack *stack);
//销毁栈
void stackDestory(Stack *stack);
//判空
int stackIsEmpty(Stack *stack);
//入栈
int stackPush(Stack *stack, int val);
//出栈 （若出栈错误，则返回-1）
int stackPop(Stack *stack);
//取栈顶元素 （若取栈顶元素错误，则返回-1）
int GetTopElement(Stack *stack);

#endif /* StackTool_h */
