#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

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

int main()
{
    map<int, int> parent;

    parent[0] = 0;
    parent[2] = 0;
    parent[1] = 2;
    parent[3] = 2;
    parent[4] = 1;
    parent[5] = 4;

    int representative = findSet(5, parent);
    cout << "representative: " << representative;

    return 0;
}