//approach: divide and conquer

#include "bits/stdc++.h"

using namespace std;

struct elementBlock
{
    int minimumValue;
    int maximumValue;
};

elementBlock combineFunc(elementBlock datasetLeft, elementBlock datasetRight)
{
    elementBlock finalDatas;

    finalDatas.minimumValue = min(datasetLeft.minimumValue, datasetRight.minimumValue);
    finalDatas.maximumValue = max(datasetLeft.maximumValue, datasetRight.maximumValue);

    return finalDatas;
}

elementBlock minmaxFunc(vector<int>& dataSet, int low, int high)
{
    //conquer
    elementBlock dataBlock;

    if(low == high) //when there is one child
    {
        dataBlock.maximumValue = dataSet[low];
        dataBlock.minimumValue = dataSet[low];

        return dataBlock;
    }
    if(high-low == 1) //when there are two child
    {
        if(dataSet[low] < dataSet[high])
        {
            dataBlock.minimumValue = dataSet[low];
            dataBlock.maximumValue = dataSet[high];
        }
        else
        {
            dataBlock.minimumValue = dataSet[high];
            dataBlock.maximumValue = dataSet[low];
        }
        
        return dataBlock;
    }
    else //when there are more than two child
    {
        //divide
        int mid = (low+high)/2;
        elementBlock leftSide = minmaxFunc(dataSet, low, mid);
        elementBlock rightSide = minmaxFunc(dataSet, mid+1, high);

        //combine
        elementBlock combineResults = combineFunc(leftSide, rightSide);

        return combineResults;
    }
}

int main()
{
    vector<int> dataSet(10);

    int index = 0;
    int size = dataSet.size();
    while(index < size)
    {
        cin >> dataSet[index];
        index++;
    }
    //input: 0 9 6 7 8 1 4 5 3 2

    int low = 0;
    elementBlock resultBlock;
    resultBlock = minmaxFunc(dataSet, low, size-1);

    //print results
    cout << "MINIMUM Value: " << resultBlock.minimumValue << "\nMAXIMUM Value: " << resultBlock.maximumValue << endl;

    return 0;
}