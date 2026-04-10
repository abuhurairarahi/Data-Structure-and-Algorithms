#include "bits/stdc++.h"

using namespace std;

int kadaneAlgo(vector<int>& dataSet)
{
    int sum = 0;
    int maxSum = dataSet[0];
    int index = 0;

    while(index < dataSet.size())   //O(n)
    {
        //step:01
        sum += dataSet[index];

        //step:02
        maxSum = max(sum, maxSum);

        //step:03
        if(sum < 0)
        {
            sum = 0;
        }

        index++;
    }

    return maxSum;
}

int main()
{
    vector<int> dataSet = {-1, -2, -9};

    int maxSum = kadaneAlgo(dataSet);

    cout << "Maximum Sum: " << maxSum << endl;

    return 0;
}