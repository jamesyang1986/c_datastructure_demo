//
// Created by james on 2022/2/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int isEmpty(List *list){
    if(list == NULL)
        return 0;
    return list->len;

}

List *listCreate(void ){
    struct List *list;
    if((list = malloc(sizeof (*list))) == NULL)
        return NULL;
    list->head = list->tail == NULL;
    list->len = 0;
    return list;

}

void listRelease(List *list){
    if(list == NULL){
        return;
    }

    ListNode  *current, *tmp;
    current = list->head;
    while(current != NULL){
        tmp = current;
        current = current->next;
        free(tmp);
    }
    free(list);

}
List *listAddNodeHead(List *list, void *value){
    if(list == NULL)
        return NULL;

    struct ListNode *listNode;
    if((listNode = malloc(sizeof(*listNode))) == NULL)
        return NULL;
    listNode->value = value;
    listNode->next = NULL;

    if(list->head == NULL){
       list->head = list->tail = listNode;
       listNode->next = NULL;
    }else{
        listNode->next = list->head;
        list->head = listNode;

    }

    list->len++;
    return list;
}

List *listAddNodeTail(List *list, void *value){
    if(list == NULL)
        return NULL;

    struct ListNode *listNode;
    if((listNode = malloc(sizeof(*listNode))) == NULL)
        return NULL;
    listNode->value = value;
    listNode->next = NULL;

    if(list->len == 0){
        list->head = list->tail = listNode;
        listNode->next = NULL;
    }else{
        list->tail->next = listNode;
        list->tail = listNode;
    }
    list->len++;
    return list;
}

void listDelNode(List *list, ListNode *listNode){
    if(list == NULL || listNode == NULL)
        return;
    ListNode *current,*prev = list->head;
    while(current != NULL ){
        if(current->value && (current->value == listNode ->value)) {
            if (current == list->head) {
                list->head = list->head->next;
                free(current);
                return;
            } else {
                prev->next = current->next;
                prev = current;
                free(current);
                return;
            }
        }else{
            prev = current;
            current = current->next;
        }
    }


}
ListNode *listSearchKey(List *list, void *key){
    if(list == NULL || list->head == NULL)
        return NULL;
    ListNode *current = list->head;
    while(current != NULL){
        if(current->value == key)
            return current;
        current = current->next;
    }
    return NULL;
}

ListNode *listIndex(List *list, int index){
    if(list == NULL || list->head == NULL || index > list->len || index < 0)
        return NULL;
    ListNode *current = list->head;
    while(index-- && current != NULL){
        current = current->next;
    }

    return current;

}
