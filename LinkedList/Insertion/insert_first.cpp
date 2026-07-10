#include "stdio.h"
#include "stdlib.h"

struct listNode
{
    int data;
    listNode* nextAddress;
    //linked-list type: SINGLY
};

listNode* head = NULL;
listNode* tail = NULL;

listNode* createnode (int data)
{
    listNode* tempNode = (listNode*)malloc(sizeof(listNode));
    tempNode->data = data;
    tempNode->nextAddress = NULL;

    return tempNode;
}

void insertFirst (int data)
{
    if(head == NULL)
    {
        listNode* tempNode = createnode(data);
        head = tempNode;
        tail = tempNode;
    }
    else
    {
        listNode* tempNode = createnode(data);
        tempNode->nextAddress = head;
        head = tempNode;
    }
}

int main()
{
    //By using this method, the time complexity if O(1)
    insertFirst(10);
    insertFirst(20);
    insertFirst(30);
    insertFirst(40);
    insertFirst(50);

    listNode* iteration = head;
    while(iteration != NULL)
    {
        printf("%d ", iteration->data);
        iteration = iteration->nextAddress;
    }

    return 0;
}