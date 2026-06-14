#include "bits/stdc++.h"

using namespace std;

struct info
{
    int totalpathCost;
    vector<int> MST;
};

info buildMST (vector<vector<int>> &adjMatrix, int source)
{
    //min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> edgeContainer;
    //visited array
    vector<bool> visitedArray (3, false);
    //parent array
    vector<int> parent (3, 0);
    //count total path cost
    int totalCost = 0;

    visitedArray[source] = true;
    parent[source] = source;

    for(int i = 0; i < 3; i++)
    {
        if(adjMatrix[source][i] > 0)
        {
            int pathCost = adjMatrix[source][i];
            int destination = i;

            edgeContainer.emplace(pathCost, destination);
        }
    }

    while(!edgeContainer.empty())
    {
        auto [pathCost, destination] = edgeContainer.top();

        if(visitedArray[destination] == false)
        {
            visitedArray[destination] = true;
            parent[destination] = source;
            totalCost += pathCost;
            source = destination;
            edgeContainer.pop();

            for(int i = 0; i < 3; i++)
            {
                if (adjMatrix[source][i] > 0)
                {
                    int pathcost = adjMatrix[source][i];
                    int Destination = i;

                    edgeContainer.emplace(pathcost, Destination);
                }
            }
        }
        else
        {
            edgeContainer.pop();
        }
    }

    info res;
    res.MST = parent;
    res.totalpathCost = totalCost;

    return res;

}

int main()
{
    //taking the graph as adjacency matrix using 2d data structure
    vector<vector<int>> adjMartix = {
        {0, 2, 1}, //0
        {2, 0, 7}, //1
        {1, 7, 0}  //2
       //0  1  2 
    };

    //fixing a source node
    int source = 2;

    //fucntion call
    info res = buildMST(adjMartix, source);
    for(int i = 0; i < 3; i++)
    {
        if(i != res.MST[i])
        {
            cout << res.MST[i] << " --> " << i << endl;
        }
    }

    cout << res.totalpathCost;
}