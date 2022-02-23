#include <stdio.h>
#include "list.h"


int main() {
    printf("==============c alg test demo=========!\n");
    List *list = listCreate();
    for(int i = 0; i < 10; i++){
        listAddNodeHead(list,i);
    }

    printf("the list len is %d\n", list->len);

    ListNode *findNode = listSearchKey(list,5);
    printf("find the key %d\n", findNode->value);

//    listDelNode(list,findNode);

    printf("the list len is %d\n", list->len);

    ListNode  *listNode = listIndex(list,6);

    printf("the key of index %d, is:%d\n",6, listNode->value);
    listRelease(list);

    return 0;
}
