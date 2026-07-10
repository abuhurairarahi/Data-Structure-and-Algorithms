#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int zero_oneKnapsack(int items, int capacity, vector<int> &itemWeight, vector<int> &itemPrice)
{
    vector<vector<int>> knapsackTable(items+1, vector<int> (capacity+1));
    for(int rowIndex = 0; rowIndex <= items; rowIndex++)
    {
        for(int colIndex = 0; colIndex <= capacity; colIndex++)
        {
            knapsackTable[rowIndex][colIndex] = 0;
        }
    }

    for(int rowIndex = 1; rowIndex <= items; rowIndex++)
    {
        for(int colIndex = 1; colIndex <= capacity; colIndex++)
        {
            if(colIndex >= itemWeight[rowIndex-1])
            {
                int elementTaken = itemPrice[rowIndex - 1] + knapsackTable[rowIndex - 1][colIndex - itemWeight[rowIndex - 1]];
                int elementNotTaken = knapsackTable[rowIndex - 1][colIndex];
                knapsackTable[rowIndex][colIndex] = max(elementTaken, elementNotTaken);
            }
            else
            {
                knapsackTable[rowIndex][colIndex] = knapsackTable[rowIndex - 1][colIndex];
            }
        }
    }

    return knapsackTable[items][capacity];
    
}

int main()
{
    int items, capacity;
    cin >> items >> capacity;

    vector<int> itemWeight(items);
    vector<int> itemPrice(items);

    for(int index = 0; index < items; index++)
    {
        cin >> itemWeight[index] >> itemPrice[index];
    }

    int maxProfit = zero_oneKnapsack(items, capacity, itemWeight, itemPrice);
    cout << "MAX PROFTI: " << maxProfit;

    return 0;
}