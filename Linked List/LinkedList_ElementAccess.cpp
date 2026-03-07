#include <bits/stdc++.h>

using namespace std;

struct listNode
{
    int data;
    listNode* next;
};

listNode* createNode (int data)
{
    listNode* node = (listNode*)malloc(sizeof(listNode));
    node->data = data;
    node->next = NULL;

    return node;
}

listNode* head = NULL;
listNode* tail = NULL;

listNode* elementAccess (int elementPostion)
{
    listNode* address = head;
    int position = 0;
    while(position < elementPostion-1)
    {
        address = address->next;
        position++;
    }

    return address;
}

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

int main()
{
    listNode* root = NULL;

    root = nodeInsertion(root,10);
    root = nodeInsertion(root,20);
    root = nodeInsertion(root,30);
    root = nodeInsertion(root,40);
    root = nodeInsertion(root,50);
    root = nodeInsertion(root,60);
    root = nodeInsertion(root,70);
    root = nodeInsertion(root,80);
    root = nodeInsertion(root,90);
    root = nodeInsertion(root,100);


    int postion;
    cout << "Enter the position: ";
    cin >> postion;

    listNode* address = elementAccess(postion);

    cout << "Postion " << postion << " element is: " << address->data << endl;
    
    return 0;
}



