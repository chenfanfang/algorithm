//
//  main.c
//  83. 删除排序链表中的重复元素
//
//  Created by chenfanfang on 2019/8/19.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

//https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/

#include <stdio.h>
#include "PublicTool.h"

struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL || head->next == NULL ) {
        return head;
    }
    
    struct ListNode *currentNode = head->next;
    struct ListNode *previousNode = head;
    while (currentNode != NULL) {
        if (previousNode->val == currentNode->val) {
            currentNode = currentNode->next;
            previousNode->next = currentNode;
            
        }
        else {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }
    
    return head;
}

//创建有重复数据、并且已经排好序的  的链表
struct ListNode *createHaveDuplicatesValueNodeList() {
    struct ListNode *headerNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *flagNode = headerNode;
    for (int i = 0; i <= 10; i++) {
        
        if (i == 4 || i == 7) {
            for (int j = 0; j < 3; j++) {
                struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
                node->val = i;
                flagNode->next = node;
                flagNode = node;
            }
        }
        
        else {
            struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
            node->val = i;
            flagNode->next = node;
            flagNode = node;
        }
        
    }
    
    flagNode->next = NULL;
    return headerNode;
}

int main(int argc, const char * argv[]) {
    
    //创建链表
    struct ListNode *head = createHaveDuplicatesValueNodeList();
    printf("创建的链表数据为:\n");
    printfNodeList(head);
    printf("\n\n\n");
    
    
    //83. 删除排序链表中的重复元素
    struct ListNode *newHead = deleteDuplicates(head);
    printf("移除 val = 6的节点后的链表数据为:\n");
    printfNodeList(newHead);
    printf("\n\n\n");
    
    return 0;
}
