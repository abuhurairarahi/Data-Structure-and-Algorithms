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

void insert_at_position (int data, int position)
{
    if(position < 0)
    {
        printf("Position Negative!\n");
        return;
    }
    if(position == 0)
    {
        insertFirst(data);
        return;
    }
    else
    {
        int count = 0;
        listNode* iteration = head;
        while (iteration != NULL)
        {
            if(count == position-1)
            {
                listNode* tempNode = createnode(data);
                listNode* postNode = iteration->nextAddress;

                iteration->nextAddress = tempNode;
                tempNode->nextAddress = postNode;
                return;
            }

            count++;
            iteration = iteration->nextAddress;
        }
        
        printf("Position Not Found!\n");
    }
}


int main()
{
    insert_at_position(10,10);
    insert_at_position(10,0);
    insert_at_position(20,-1);
    insert_at_position(20,1);
    insert_at_position(30,2);
    insert_at_position(40,3);
    insert_at_position(25,2);
    insert_at_position(22,2);
    insert_at_position(5,0);

    listNode* iteration = head;
    while(iteration != NULL)
    {
        printf("%d ", iteration->data);
        iteration = iteration->nextAddress;
    }

    return 0;
}