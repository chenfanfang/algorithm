//
//  PublicTool.h
//  算法
//
//  Created by chenfanfang on 2019/8/19.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#ifndef PublicTool_h
#define PublicTool_h

#include <stdio.h>
#include <stdlib.h>

//数组长度
#define ARRAY_LENGTH(arr) (sizeof(arr)/sizeof((arr)[0]))

//定义节点结构体
struct ListNode{
    int val;
    struct ListNode *next;
};


//创建链表,值为  0、1、2.....nodCount
struct ListNode *createNodeList(int nodeCount);

//根据数组的值来创建链表
struct ListNode *createNodeListWithValueArr(int valueArr[], int length);


//打印链表里面的数据
void printfNodeList(struct ListNode *headNode);

#endif /* PublicTool_h */
