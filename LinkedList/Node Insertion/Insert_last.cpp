#include "stdio.h"
#include "stdlib.h"

struct listNode
{
    int data;
    listNode* nextAddress;
};

//tracker initialization
listNode* head = NULL;
listNode* tail = NULL;

listNode* createnode (int data)
{
    listNode* tempNode = (listNode*)malloc(sizeof(listNode));
    tempNode->data = data;
    tempNode->nextAddress = NULL;

    return tempNode;
}

void insertLast (int data)
{
    if(head == NULL)
    {
        listNode* tempNode = createnode(data);

        //assigning head & tail 
        head = tempNode;
        tail = tempNode;
    
        //nodeA -> NULL (h=t=nodeA)
    }
    else
    {
        listNode* tempNode = createnode(data);
        //connecting the newest node with the existing tail
        tail->nextAddress = tempNode;
        //re-assigning the tail
        tail = tempNode;
    
        //nodeA -> nodeB -> NULL (h=nodeA t=nodeB)
        //nodeA -> nodeB -> nodeC (h=nodeA t=nodeC)
    }
}

int main()
{   
    //Using this method: Time Complexity becomes O(1) 
    insertLast(10);
    insertLast(20);
    insertLast(30);
    insertLast(40);
    insertLast(50);

    listNode* iteration = head;
    while(iteration != NULL)
    {
        printf("%d ", iteration->data);
        iteration = iteration->nextAddress;
    }

    return 0;
}