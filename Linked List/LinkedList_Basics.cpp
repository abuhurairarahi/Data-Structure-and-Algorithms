#include <bits/stdc++.h>

using namespace std;

struct listNode
{
    int data;
    listNode* next;   // pointer to next node (singly linked list)
};

// function to create a new node
listNode* createNode(int data)
{
    listNode* node = (listNode*)malloc(sizeof(listNode));

    node->data = data;
    node->next = NULL;

    cout << "Node created with data: " << data << endl;

    return node;
}

int main()
{
    cout << "Creating nodes..." << endl << endl;

    listNode* elementOne = createNode(10);
    /*
         ----
        | 10 | -----> NULL
         ----  (next)
    
    */
    listNode* elementTwo = createNode(20);
    cout << "Connecting elementOne -> elementTwo" << endl;
    elementOne->next = elementTwo;
    /*
         ----       ----
        | 10 | --> | 20 | --> NULL
         ----       ----
       
    */
    listNode* elementThree = createNode(30);
    cout << "Connecting elementTwo -> elementThree" << endl;
    elementTwo->next = elementThree;
    /*
         ----       ----       ----
        | 10 | --> | 20 | --> | 30 | --> NULL
         ----       ----       ----
       
    */
    listNode* elementFour = createNode(40);
    cout << "Connecting elementThree -> elementFour" << endl;
    elementThree->next = elementFour;
    /*
         ----       ----       ----       ----
        | 10 | --> | 20 | --> | 30 | --> | 40 | --> NULL
         ----       ----       ----       ----
       
    */
    listNode* elementFive = createNode(50);
    cout << "Connecting elementFour -> elementFive" << endl;
    elementFour->next = elementFive;
    /*
         ----       ----       ----       ----       ----
        | 10 | --> | 20 | --> | 30 | --> | 40 | --> | 50 | --> NULL
         ----       ----       ----       ----       ----
       
    */
    cout << "\nLinked List created successfully." << endl;

    cout << "\nTraversing the Linked List:\n" << endl;

    // printing all nodes using traversal
    listNode* Address = elementOne;

    while(Address != NULL)
    // the left of the last element is NULL. "elementFive->left = NULL" 
    {
        cout << "Current Node Data: " << Address->data << endl;

        Address = Address->next;  
        /*
            move to next node
            
            elementOne->next  ---->  elementTwo
            elementTwo->next  ---->  elementThree
            elementThree->next  ---->  elementFour
            elementFour->next  ---->  elementFive
            elementFive->next  ---->  NULL
        */
    }

    cout << "\nEnd of Linked List reached (NULL)." << endl;

    return 0;
}