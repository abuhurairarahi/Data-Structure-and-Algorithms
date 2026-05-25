#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void makeSet(int element, map<int, int> &parent)
{
    parent[element] = element;

    return;
}

int main()
{
    int numberofElement, element;
    cin >> numberofElement;
    map<int, int> parent;

    for(int index = 0; index < numberofElement; index++)
    {
        cin >> element;
        makeSet(element, parent);
    }

    for(auto x : parent)
    {
        cout << x.first << " - " << x.second << endl;
    }

    return 0;
}