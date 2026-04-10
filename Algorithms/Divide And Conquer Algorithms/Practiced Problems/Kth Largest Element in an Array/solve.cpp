#include "bits/stdc++.h"

using namespace std;

void Merge(vector<int>& dataSet, int low, int high, int mid, int Size) //O(n)
{
    int i = low;
    int j = mid+1;
    vector<int> tempData(Size);
    int index = low;

    while(i <= mid && j <= high)
    {
        if(dataSet[i] < dataSet[j])
        {
            tempData[index] = dataSet[i];
            i++;
            index++;
        }
        else
        {
            tempData[index] = dataSet[j];
            j++;
            index++;
        }
    }

    if(i > mid)
    {
        while(j <= high)
        {
            tempData[index] = dataSet[j];
            j++;
            index++;
        }
    }
    else
    {
        while(i <= mid)
        {
            tempData[index] = dataSet[i];
            i++;
            index++;
        }
    }

    //transfer the tempdata to main dataset
    int tempIndex = low;
    while(tempIndex <= high)
    {
        dataSet[tempIndex] = tempData[tempIndex];
        tempIndex++;
    }

}

void mergeSort(vector<int>& dataSet, int low, int high) //O(nlogn)
{
    if(low < high)
    {
        int mid = (low+high)/2;

        mergeSort(dataSet, low, mid);
        mergeSort(dataSet, mid+1, high);

        //combine
        Merge(dataSet, low, high, mid, dataSet.size());

    }
}

int findkthMax (vector<int>& dataSet, int k)
{
    mergeSort(dataSet, 0, (dataSet.size()-1));
    return dataSet[(dataSet.size() - k)]; //O(1)
}

int findkthMin (vector<int>& dataSet, int k)
{
    mergeSort(dataSet, 0, (dataSet.size()-1));
    return dataSet[0+(k-1)]; //O(1)
}

int main()
{
    vector<int> dataSet = {100, 95, 90, 120, 110, 98, 88}; //dataSet size = 7

    int K = 7;
    int kthMax = findkthMax(dataSet, K);
    int kthMin = findkthMin(dataSet, K);

    cout << K << "th Max: " << kthMax << endl << K << "th Min: " << kthMin << endl;

    //time complexity: O(nlogn)

    return 0;
}