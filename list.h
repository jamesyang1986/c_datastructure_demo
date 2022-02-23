//
// Created by james on 2022/2/23.
//
#ifndef C_LIST_H
#define C_LIST_H

typedef struct ListNode{
    struct ListNode *next;
    void *value;
}ListNode;

typedef struct List{
    struct ListNode *head;
    struct ListNode *tail;
    int len;
}List;

int isEmpty(List *list);
List *listCreate(void );
void listRelease(List *list);
List *listAddNodeHead(List *list, void *value);
List *listAddNodeTail(List *list, void *value);
void listDelNode(List *list, ListNode *listNode);
ListNode *listSearchKey(List *list, void *key);
ListNode *listIndex(List *list, int index);

#endif