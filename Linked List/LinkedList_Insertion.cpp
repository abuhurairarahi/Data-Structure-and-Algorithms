#include <bits/stdc++.h>

using namespace std;

struct listNode
{
    int data;
    listNode *next; // pointer to next node (singly linked list)
};

listNode *createNode(int data)
{
    listNode *node = (listNode *)malloc(sizeof(listNode));
    node->data = data;
    node->next = NULL;

    return node;
}

// initializing the first & last address

listNode *head = NULL;
listNode *tail = NULL;

listNode *nodeInsertion(listNode *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        head = tail = root;
        return root;
    }
    else
    {
        listNode *tempElement = createNode(data);
        root->next = tempElement;

        // update tail
        tail = tempElement;
        return tempElement;
    }

    // Input Time Complexity O(n)
}

void printLinkedlist(listNode *head, listNode *tail)
{
    listNode *address = head;
    while (address != tail->next) // as tail->left = NULL
    {
        cout << address->data << " ";
        address = address->next;
    }
    cout << endl;

    // Output Time Complexity O(n)
}

void inputNode(listNode *root)
{
    int data, choice;

    while (true)
    {
        cout << "1. Take Node Input\n2. Print Linked List\n3. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter an element: ";
            cin >> data;

            root = nodeInsertion(root, data);
        }
        else if (choice == 2)
        {
            // printing the whole linked list
            printLinkedlist(head, tail);
        }
        else
        {
            return;
        }
    }
}

int main()
{
    listNode *root = NULL;


    // Manual Input

    root = nodeInsertion(root, 10);
    cout << "First Element: " << root->data << endl;

    root = nodeInsertion(root, 20);
    cout << "Second Element: " << root->data << endl;

    root = nodeInsertion(root, 30);
    cout << "Third Element: " << root->data << endl;

    root = nodeInsertion(root, 40);
    cout << "Fourth Element: " << root->data << endl;

    root = nodeInsertion(root, 50);
    cout << "Fifth Element: " << root->data << endl;

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;


    // Automated Input

    inputNode(root);


    /*
    
    #TIME COMPLEXITY:

    INPUT  ---> O(n)
    OUTPUT ---> O(n)
    ACCESS ---> O(n)
    DELETE ---> O(n)

    */

    return 0;
}