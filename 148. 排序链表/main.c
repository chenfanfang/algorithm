//
//  main.c
//  148. 排序链表
//
//  Created by chenfanfang on 2019/8/20.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

//https://leetcode-cn.com/problems/sort-list/

#include <stdio.h>
#include "PublicTool.h"

// 未实现
struct ListNode* sortList(struct ListNode* head){
    
//    while (head) {
//        <#statements#>
//    }
    return NULL;
}


int main(int argc, const char * argv[]) {
    
    //创建链表
    int valueArr[] = {5,4,2,6,8};
    struct ListNode *head = createNodeListWithValueArr(valueArr, ARRAY_LENGTH(valueArr));
    printf("创建的链表数据为:\n");
    printfNodeList(head);
    printf("\n\n");
    
    //链表排序
    struct ListNode *newHead = sortList(head);
    printf("排完序的链表数据为:\n");
    printfNodeList(newHead);
    printf("\n\n");
    
    return 0;
}
