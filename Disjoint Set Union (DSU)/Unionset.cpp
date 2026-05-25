#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void makeSet(int element, map<int, int> &parent, map<int, int> &rank)
{
    parent[element] = element;
    rank[element] = 0;

    return;
}

int findSet(int element, map<int, int> &parent)
{
    if(parent[element] == element)
    {
        return parent[element];
    }
    else
    {
        int tempParent = findSet(parent[element], parent); 

        parent[element] = tempParent;
        //It makes the programme OPTIMAL. Reduce the time complexity O(Vertices) to O(1);

        return tempParent;
    }
}

void unionSet(int elementA, int elementB, map<int, int> &parent, map<int, int> &rank)
{
    int representativeA = findSet(elementA, parent);
    int representativeB = findSet(elementB, parent);

    if(representativeA == representativeB)
    {
        cout << "Already Connected" << endl;
        return;
    }
    else
    {
        if(rank[representativeA] > rank[representativeB])
        {
            parent[representativeB] = representativeA;
            return;
        }
        else if(rank[representativeA] < rank[representativeB])
        {
            parent[representativeA] = representativeB;
            return;
        }
        else
        {
            parent[representativeB] = representativeA;
            rank[representativeA] += 1;
            return;
        }

    }
}

int main()
{
    // int numberofElement, element;
    // cin >> numberofElement;
    map<int, int> parent;
    map<int, int> rank;

    // for(int index = 0; index < numberofElement; index++)
    // {
    //     cin >> element;
    //     makeSet(element, parent, rank);
    // }

    makeSet(0, parent, rank);
    makeSet(5, parent, rank);
    makeSet(10, parent, rank);
    makeSet(15, parent, rank);
    makeSet(20, parent, rank);
    makeSet(25, parent, rank);
    makeSet(30, parent, rank);

    cout << "Parent after makeset" << endl;
    for(auto x : parent)
    {
        cout << x.first << "->" << x.second << endl;
    }

    unionSet(0, 10, parent, rank);
    unionSet(10, 5, parent, rank);
    unionSet(10, 15, parent, rank);

    unionSet(30, 25, parent, rank);
    unionSet(25, 20, parent, rank);

    cout << "Parent after unionset" << endl;
    for(auto x : parent)
    {
        cout << x.first << "->" << x.second << endl;
    }
    cout << "Rank after unionset" << endl;
    for(auto x : rank)
    {
        cout << x.first << "->" << x.second << endl;
    }

    int repA = findSet(20, parent);
    int repB = findSet(5, parent);
    cout << repA << " " << repB << endl;

    return 0;
}