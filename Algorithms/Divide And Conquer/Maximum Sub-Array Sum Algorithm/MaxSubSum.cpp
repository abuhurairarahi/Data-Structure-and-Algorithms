#include "bits/stdc++.h"

using namespace std;

struct sumIndextracker
{
    int sum;
    int startIndex;
    int endIndex;
};

sumIndextracker combineSum (vector<int>& dataSet, int low, int mid, int high)
{
    sumIndextracker tempCSUM;
    int tempSum = 0;
    int i = mid;
    int j = mid+1;

    //solving leftsum
    sumIndextracker leftSum;
    leftSum.sum = dataSet[i];
    leftSum.startIndex = i;
    leftSum.endIndex = i;

    while(i >= low)
    {
        tempSum += dataSet[i];
        if(tempSum > leftSum.sum)
        {
            leftSum.sum = tempSum;
            leftSum.startIndex = i;
        }
        i--;
    }

    //solving rightsum
    tempSum = 0; 
    sumIndextracker rightSum;
    rightSum.sum = dataSet[mid+1];
    rightSum.startIndex = j;
    rightSum.endIndex = j;

    while(j <= high)
    {
        tempSum += dataSet[j];
        if(tempSum > rightSum.sum)
        {
            rightSum.sum = tempSum;
            rightSum.endIndex = j;
        }
        j++;
    }

    tempCSUM.sum = leftSum.sum + rightSum.sum;
    tempCSUM.startIndex = leftSum.startIndex;
    tempCSUM.endIndex = rightSum.endIndex;

    return tempCSUM;
}

sumIndextracker compareSum(sumIndextracker leftSum, sumIndextracker rightSum, sumIndextracker cSum)
{
    if(leftSum.sum >= rightSum.sum && leftSum.sum >= cSum.sum)
    {
        return leftSum;
    }
    else if(rightSum.sum >= leftSum.sum && rightSum.sum >= cSum.sum)
    {
        return rightSum;
    }
    else
    {
        return cSum;
    }
}

sumIndextracker subArray (vector<int>& dataSet, int low, int high)
{
    sumIndextracker tempTracker;

    if(low == high)
    {
        tempTracker.sum = dataSet[high];
        tempTracker.startIndex = low;
        tempTracker.endIndex = high;
        
        return tempTracker;
    }
    else
    {
        int mid = (low+high)/2;

        sumIndextracker leftSum = subArray(dataSet, low, mid);
        sumIndextracker rightSum = subArray(dataSet, mid+1, high);
        sumIndextracker cSum = combineSum (dataSet, low, mid, high);

        tempTracker = compareSum(leftSum, rightSum, cSum);

        return tempTracker;
    }
}

int main()
{
    int N;
	cout << "Enter the size: ";
	cin >> N;

    vector<int> dataSet(N);
    for(int i = 0; i < dataSet.size(); i++)
    {
    	cout << "Input for index " << i << ": ";
    	cin >> dataSet[i];
    }

    sumIndextracker resultSum = subArray(dataSet, 0, (dataSet.size() - 1));

    cout << "Sum: " << resultSum.sum << endl << "Start Index: " << resultSum.startIndex << endl << "End Index: " << resultSum.endIndex << endl;
    
    return 0;
}