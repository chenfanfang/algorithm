//
//  main.c
//  707. 设计链表
//
//  Created by chenfanfang on 2019/8/21.
//  Copyright © 2019 chenfanfang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

/*
 【题目】
 
 设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。
 
 在链表类中实现这些功能：
 
 get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
 addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
 addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
 addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
 deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
  
 
 示例：
 
 MyLinkedList linkedList = new MyLinkedList();
 linkedList.addAtHead(1);
 linkedList.addAtTail(3);
 linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
 linkedList.get(1);            //返回2
 linkedList.deleteAtIndex(1);  //现在链表是1-> 3
 linkedList.get(1);            //返回3
  
 
 提示：
 
 所有val值都在 [1, 1000] 之内。
 操作次数将在  [1, 1000] 之内。
 请不要使用内置的 LinkedList 库。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/design-linked-list
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */




typedef struct Node {
    struct Node *next;
    int val;
}Node;

typedef struct {
    Node *head;
    
} MyLinkedList;


////创建链表
MyLinkedList *myLinkedListCreate() {
    MyLinkedList *list = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    list->head = NULL;
    return list;
}

Node *createNode(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    //printf("sizeof:%d\n\n",sizeof(struct Node *));
    node->val = val;
    node->next = NULL;
    return node;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0) {
        return -1;
    }
    Node *node = obj->head;
    for (int i = 1; i <= index; i++) {
        node = node->next;
        if (obj == NULL) {
            return -1;
        }
    }
    return node != NULL ? node->val : -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    
    Node *new_node = createNode(val);
    new_node->next = obj->head;
    obj->head = new_node;
    
    
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node *node = obj->head;
    Node *new_node = createNode(val);
    if (node == NULL) {
        obj->head = new_node;
        return;
    }
    
    while (node->next != NULL) {
        node = node->next;
    }
    node->next = new_node;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0) return;
    
    Node *node = obj->head;
    int index_flag = 0;
    if (node == NULL) {
        return;
    }
    Node *new_node = createNode(val);
    if (node->next == NULL) {
        obj->head = new_node;
        new_node->next = node;
        return;
    }
    
    Node *previousNode = NULL;
    while (index_flag != index) {
        previousNode = node;
        index_flag++;
        node = node->next;
        if (node == NULL) {
            return;
        }
    }
    
    previousNode->next = new_node;
    new_node->next = node;
    
    
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0) {
        return;
    }
    Node *node = obj->head;
    for (int i = 1; i <= index - 1; i++) { //找到要删除node的上一个node
        node = node->next;
        if (node == NULL || node->next == NULL) {
            return;
        }
    }
    
    //MyLinkedList *delete_index_node = obj->next;
    //obj->next = delete_index_node->next;
    
    node->next = node->next->next;
    
}

//释放链表内存
void myLinkedListFree(MyLinkedList* obj) {
    Node *need_free_node;
    Node *node = obj->head;
    free(obj);
    while (node != NULL) {
        need_free_node = node;
        node = node->next;
        free(need_free_node);
    }
}



int main(int argc, const char * argv[]) {
    
    MyLinkedList *linkedList = myLinkedListCreate();
    myLinkedListAddAtHead(linkedList, 1);
    myLinkedListAddAtTail(linkedList, 3);
    myLinkedListAddAtIndex(linkedList, 1, 2);//链表变为1-> 2-> 3
    printf("%d\n",myLinkedListGet(linkedList, 1));//返回2
    myLinkedListDeleteAtIndex(linkedList, 1);//现在链表是1-> 3
    printf("%d\n",myLinkedListGet(linkedList, 1));//返回3
    
    
    
     myLinkedListFree(linkedList);
    
    return 0;
}
