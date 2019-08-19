//
//  main.c
//  876. 链表的中间结点
//
//  Created by chenfanfang on 2019/8/19.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

//https://leetcode-cn.com/problems/middle-of-the-linked-list/

#include <stdio.h>
#include "PublicTool.h"

struct ListNode* middleNode(struct ListNode* head){
    
    int nodeCount = 0;
    struct ListNode *flagNode = head;
    while (flagNode != NULL) {
        nodeCount++;
        flagNode = flagNode->next;
    }
    
    int index = (nodeCount - 1) / 2;
    if ((nodeCount - 1) % 2 != 0) {
        index++;
    }
    
    flagNode = head;
    for (int i = 1; i <= index; i++) {
        flagNode = flagNode->next;
    }
    
    return flagNode;
}


int main(int argc, const char * argv[]) {
    
    //创建链表
    struct ListNode *head = createNodeList(9);
    printf("创建的链表数据为:\n");
    printfNodeList(head);
    printf("\n\n\n");
    
    
    struct ListNode *middle_Node = middleNode(head);
    printf("链表的中间结点数据为:%d\n",middle_Node->val);
    printf("\n\n\n");
    
    
    return 0;
}
