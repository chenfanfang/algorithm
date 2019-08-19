//
//  main.c
//  141. 环形链表
//
//  Created by chenfanfang on 2019/8/19.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

//https://leetcode-cn.com/problems/linked-list-cycle/

#include <stdio.h>
#include "PublicTool.h"
#include <stdbool.h>

bool hasCycle(struct ListNode *head) {
    
    if (head == NULL) {
        return false;
    }
    
    struct ListNode *slowNode = head;
    struct ListNode *farstNode = head->next;
    
    while (farstNode != NULL && farstNode->next != NULL && farstNode->next->next != NULL) {
        if (farstNode == slowNode) {
            return true;
        }
        farstNode = farstNode->next->next;
        slowNode = slowNode->next;
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    
    //创建环形链表链表
    struct ListNode *head1 = createNodeList(10);
    struct ListNode *last1 = head1;
    while (last1->next != NULL) {
        last1 = last1->next;
    }
    last1->next = head1;
    
    bool hasCycle1 = hasCycle(head1);
    
    printf("是否是环形链表:%d\n\n",hasCycle1);
    
    
    //创建非环形链表链表
    struct ListNode *head2 = createNodeList(10);
    bool hasCycle2 = hasCycle(head2);
    printf("是否是环形链表:%d\n\n",hasCycle2);
    
    return 0;
}
