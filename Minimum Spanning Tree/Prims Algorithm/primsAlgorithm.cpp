#include "bits/stdc++.h"

using namespace std;

struct info
{
    int pathCost;
    vector<int> finalMST;
};

info buildMST(vector<vector<int>> &adjacentList, int totalVertices, int source)
{
    // MIN_HEAP
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> edgeContainer;
    vector<bool> visitedArray(totalVertices, false);
    vector<int> MST(totalVertices, 0);
    int totalPathWeight = 0;

    MST[source] = source;
    visitedArray[source] = true;

    for (int i = 0; i < totalVertices; i++)
    {
        if (adjacentList[source][i] > 0)
        {
            edgeContainer.emplace(adjacentList[source][i], i);
        }
    }

    while (!edgeContainer.empty())
    {
        auto [pathCost, destination] = edgeContainer.top();

        if (visitedArray[destination] == false)
        {
            visitedArray[destination] = true;
            MST[destination] = source;
            totalPathWeight += pathCost;
            source = destination;
            edgeContainer.pop();

            for (int i = 0; i < totalVertices; i++)
            {
                if (adjacentList[source][i] > 0)
                {
                    edgeContainer.emplace(adjacentList[source][i], i);
                }
            }
        }
        else
        {
            edgeContainer.pop();
        }
    }

    info res;
    res.finalMST = MST;
    res.pathCost = totalPathWeight;

    return res;
}

int main()
{
    int totalVertices;
    cout << "Number of vertices: ";
    cin >> totalVertices;

    vector<vector<int>> adjacentList(totalVertices, vector<int>(totalVertices));
    for (int indexA = 0; indexA < totalVertices; indexA++)
    {
        for (int indexB = 0; indexB < totalVertices; indexB++)
        {
            cout << "Path weight for " << indexA << " --> " << indexB << ": ";
            cin >> adjacentList[indexA][indexB];
        }
    }

    int source;
    cout << "Enter Source: ";
    cin >> source;

    info res = buildMST(adjacentList, totalVertices, source);
    for (int i = 0; i < totalVertices; i++)
    {
        if(i != res.finalMST[i])
        {
            cout << res.finalMST[i] << " --> " << i << endl;
        }
    }

    cout << "Total Path Cost: " << res.pathCost;
}