//
//  PublicTool.c
//  算法
//
//  Created by chenfanfang on 2019/8/19.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#include "PublicTool.h"

//创建链表
struct ListNode *createNodeList(int nodeCount) {
    struct ListNode *headerNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *flagNode = headerNode;
    for (int i = 0; i <= nodeCount; i++) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = i;
        flagNode->next = node;
        flagNode = node;
    }
    
    flagNode->next = NULL;
    return headerNode;
}

//根据数组的值来创建链表
struct ListNode *createNodeListWithValueArr(int valueArr[], int length) {
    struct ListNode *headerNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *flagNode = headerNode;
    for (int i = 0; i < length; i++) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = valueArr[i];
        flagNode->next = node;
        flagNode = node;
    }
    
    flagNode->next = NULL;
    return headerNode;
}

//打印链表里面的数据
void printfNodeList(struct ListNode *headNode) {
    
    struct ListNode *listNode = headNode->next;
    while (listNode) {
        printf("%3d",listNode->val);
        if (listNode->next != NULL) {
            printf("  ->");
        }
        listNode = listNode->next;
        
    }
    printf("\n");
}
