#include "stdio.h"
#include "stdlib.h"

struct listNode
{
    int data;
    listNode* nextAddress;
    
    //As this linked-list flows in only one direction, it's called --> SINGLY
};

listNode* createnode (int data)
{
    listNode* tempNode = (listNode*)malloc(sizeof(listNode));
    //default datatype of malloc (void*)
    tempNode->data = data;
    tempNode->nextAddress = NULL;
    
    return tempNode;
}

int main()
{
    listNode* nodeA = createnode(1);
    listNode* nodeB = createnode(2);

    //Access node data
    printf("%d\n", nodeA->data);

    //Connect nodes
    nodeA->nextAddress = nodeB;
    printf("%d", nodeA->nextAddress->data);

    return 0;
}