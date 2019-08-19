//
//  main.c
//  237. 删除链表中的节点
//
//  Created by chenfanfang on 2019/8/19.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

//https://leetcode-cn.com/problems/delete-node-in-a-linked-list/

#include <stdio.h>
#include <stdlib.h>
#include "PublicTool.h"

void deleteNode(struct ListNode* node) {
    
    node->val = node->next->val;
    node->next = node->next->next;
}

int main(int argc, const char * argv[]) {
    
    //创建链表
    struct ListNode *head = createNodeList(10);
    
    //打印创建的链表
    printf("创建的链表数据为:\n");
    printfNodeList(head);
    printf("\n\n\n");
    
    //删除某个node(假设删除的node为 val为5的node)
    struct ListNode *node5 = head;
    for (int i = 0; i <= 5 ; i++) {
        node5 = node5->next;
    }
    
    deleteNode(node5);
    
    
    printf("删除node5节点后的链表数据为:\n");
    printfNodeList(head);
    printf("\n\n\n");
    
    return 0;
}
