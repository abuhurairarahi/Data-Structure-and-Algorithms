#include "stdio.h"
#include "stdlib.h"

struct listNode
{
    int data;
    listNode* nextAddress;
};

listNode* createnode (int data)
{
    listNode* tempNode = (listNode*)malloc(sizeof(listNode));
    tempNode->data = data;
    tempNode->nextAddress = NULL;
    
    return tempNode;
}

listNode* head = NULL;
listNode* tail = NULL;

bool searchNode (int key)
{
    listNode* iteration = head;
    while(iteration != NULL)
    {
        if(iteration->data == key)
        {
            return true;
        }

        iteration = iteration->nextAddress;
    }

    return false;
}

void deleteNode (int key)
{
    if(head == NULL)
    {
        //if there exists no node!
        printf("No data exists!");
        return;
    }
    if(head->data == key)
    {
        listNode* delNode = head;
        head = head->nextAddress;
        free(delNode);

        printf("Successfully Deleted!\n");
        return;
    }
    else
    {
        listNode* iteration = head;
        while(iteration->nextAddress != NULL)
        {
            if(iteration->nextAddress->data == key)
            {
                listNode* delNode = iteration->nextAddress;
                listNode* postNode = delNode->nextAddress;

                /*
                core structure: iteratedNode --> delNode --> postNode
                updated structure: iteratedNode --> postNode
                free the memory: free(delNode) 
                */

                iteration->nextAddress = postNode;
                free(delNode);

                printf("Successfully Deleted!\n");
                return;
            }

            iteration = iteration->nextAddress;
        }
        
        printf("Key doesn't exist!\n");
    }
}

void traveseList (listNode* startNode)
{
    listNode* iterate = startNode;
    while(iterate != NULL)
    {
        printf("%d ", iterate->data);
        iterate = iterate->nextAddress;
    }
}

int main()
{
    listNode* nodeA = createnode(1);
    listNode* nodeB = createnode(2);
    listNode* nodeC = createnode(3);
    listNode* nodeD = createnode(4);
    listNode* nodeE = createnode(5);

    //manual connection
    nodeA->nextAddress = nodeB;
    nodeB->nextAddress = nodeC;
    nodeC->nextAddress = nodeD;
    nodeD->nextAddress = nodeE;

    //assigning tracker
    head = nodeA;
    tail = nodeE;

    bool searchResult = searchNode(3);
    printf("%d\n", searchResult);

    deleteNode(3);
    traveseList(head);

    return 0;
}