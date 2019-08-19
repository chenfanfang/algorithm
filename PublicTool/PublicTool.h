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

//定义节点结构体
struct ListNode{
    int val;
    struct ListNode *next;
};


//创建链表
struct ListNode *createNodeList(int nodeCount);

//打印链表里面的数据
void printfNodeList(struct ListNode *headNode);

#endif /* PublicTool_h */
