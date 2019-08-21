//
//  main.c
//  206. 反转链表
//
//  Created by chenfanfang on 2019/8/19.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

//https://leetcode-cn.com/problems/reverse-linked-list/

#include <stdio.h>
#include "PublicTool.h"


//递归法
/*
struct ListNode *reverseList(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
 */


//迭代法
struct ListNode *reverseList(struct ListNode* head){
    
    struct ListNode *previousNode = NULL;
    struct ListNode *currentNode = head;
    while (currentNode != NULL) {
        struct ListNode *nextNode = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }
    
    return previousNode;
}


int main(int argc, const char * argv[]) {
    
    //创建链表
    struct ListNode *head = createNodeList(10);
    printf("创建的链表数据为:\n");
    printfNodeList(head);
    printf("\n\n\n");
    
    
    //反转链表
    struct ListNode *newHead = reverseList(head);
    printf("反转链表后的链表数据为:\n");
    printfNodeList(newHead);
    printf("\n\n\n");
    
    return 0;
}
