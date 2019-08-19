//
//  main.c
//  203. 移除链表元素
//
//  Created by chenfanfang on 2019/8/19.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

//https://leetcode-cn.com/problems/remove-linked-list-elements/

#include <stdio.h>
#include "PublicTool.h"

struct ListNode* removeElements(struct ListNode* head, int val){

    //为null 直接return
    if (head == NULL) {
        return head;
    }
    //先处理第一个节点需要删除的情况
    while (head != NULL && head->val == val) {
        head = head->next;
    }
    
    if (head == NULL) {
        return head;
    }
    
    struct ListNode *currentNode = head->next;
    struct ListNode *prevoiusNode = head;
    while (currentNode != NULL) {
        if (currentNode->val == val) {
            currentNode = currentNode->next;
            prevoiusNode->next = currentNode;
        }
        else {
            prevoiusNode = currentNode;
            currentNode = currentNode->next;
        }
    }
    return head;
}


int main(int argc, const char * argv[]) {
    
    //创建链表
    struct ListNode *head = createNodeList(10);
    printf("创建的链表数据为:\n");
    printfNodeList(head);
    printf("\n\n\n");
    
    
    //移除 val = 6的节点
    struct ListNode *newHead = removeElements(head, 6);
    printf("移除 val = 6的节点后的链表数据为:\n");
    printfNodeList(newHead);
    printf("\n\n\n");
    
    return 0;
}
