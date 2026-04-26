#include <bits/stdc++.h>

using namespace std;

struct productInfo
{
    int weight;
    int value;
    double valueperWeight;
};

struct returnInfo
{
    double finalProfit;
    int remainedWeight;
};

bool comparator (productInfo dataA, productInfo dataB)
{
    double valueOne = dataA.valueperWeight;
    double valueTwo = dataB.valueperWeight;

    return valueOne > valueTwo;
}

returnInfo knapsackSolve (vector<productInfo> &dataSet, int capacity)
{
    double totalProfit = 0.00;

    //Type 01: (general) sort(start iterator, end iterator);
    //Type 02: (with comparator) sort(start iterator, end iterator, comparator);

    sort(dataSet.begin(), dataSet.end(), comparator); //sorted in descending order

    for(int index = 0; index < dataSet.size(); index++)
    {
        if(capacity > dataSet[index].weight)
        {
            cout << "Product " << index+1 << " has taken." << endl;
            
            totalProfit += dataSet[index].value;
            cout << "Current Profit: " << totalProfit << endl;
            
            capacity -= dataSet[index].weight;
            cout << "Remained Capacity: " << capacity << endl;
        }
        else
        {
            cout << "Product " << index+1 << " has taken." << endl;

            totalProfit += (capacity*dataSet[index].valueperWeight);
            cout << "Current Profit: " << totalProfit << endl;

            capacity = 0;
            cout << "Remained Capacity: " << capacity << endl;

            break;
        }
    }

    returnInfo retVar;

    retVar.finalProfit = totalProfit;
    retVar.remainedWeight = capacity;

    return retVar;
}

int main()
{
    int size;
    cout << "Enter the total amount of products: ";
    cin >> size;

    vector<productInfo> dataSet(size);
    
    for(int index = 0; index < size; index++)
    {
        cout << "For product " << index+1 << endl;
        
        cout << "Weight: ";
        cin >> dataSet[index].weight;

        cout << "Value: ";
        cin >> dataSet[index].value;

        dataSet[index].valueperWeight = (double) dataSet[index].value/dataSet[index].weight;
    }

    int capacity;
    cout << "Enter the capacity: ";
    cin >> capacity;

    returnInfo finalOutput = knapsackSolve(dataSet, capacity);
    cout << "Total Profit: " << finalOutput.finalProfit << endl;
    cout << "Remained Capacity: " << finalOutput.remainedWeight << endl;

    return 0;
}