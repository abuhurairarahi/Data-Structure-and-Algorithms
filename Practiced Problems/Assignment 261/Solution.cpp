#include "bits/stdc++.h"

using namespace std;

struct elementBlocks
{
    int max_score;
    int min_score;
    int max_dept_index;
    int min_dept_index;
};

int Comparisons = 0;

elementBlocks combineBlocks(elementBlocks left, elementBlocks right)
{
    elementBlocks tempElement;

    if (left.max_score > right.max_score)
    {
        Comparisons++;
        tempElement.max_score = left.max_score;
        tempElement.max_dept_index = left.max_dept_index;
    }
    else
    {
        Comparisons++;
        tempElement.max_score = right.max_score;
        tempElement.max_dept_index = right.max_dept_index;
    }


    if (left.min_score < right.min_score) 
    {
        Comparisons++;
        tempElement.min_score = left.min_score;
        tempElement.min_dept_index = left.min_dept_index;
    } 
    else 
    {
        Comparisons++;
        tempElement.min_score = right.min_score;
        tempElement.min_dept_index = right.min_dept_index;
    }

    return tempElement;
}

elementBlocks findminmaxFunc(vector<int>& dataset, int low, int high, int index)
{
    elementBlocks tempDataset;

    if(low == high)
    {
        tempDataset.min_score = dataset[low];
        tempDataset.max_score = dataset[low];
        tempDataset.max_dept_index = index;
        tempDataset.min_dept_index = index;

        return tempDataset;
    }
    if(high - low == 1)
    {
        if(dataset[low] < dataset[high])
        {
            Comparisons++;
            tempDataset.min_score = dataset[low];
            tempDataset.max_score = dataset[high];
            tempDataset.max_dept_index = index;
            tempDataset.min_dept_index = index;
        }
        else
        {
            Comparisons++;
            tempDataset.min_score = dataset[high];
            tempDataset.max_score = dataset[low];
            tempDataset.max_dept_index = index;
            tempDataset.min_dept_index = index;
        }

        return tempDataset;
    }
    else
    {
        int mid = (low+high)/2;

        elementBlocks leftSide = findminmaxFunc(dataset, low, mid, index);
        elementBlocks rightSide = findminmaxFunc(dataset, mid+1, high, index);

        //combine
        elementBlocks resultBlock = combineBlocks(leftSide, rightSide);

        return resultBlock; 
    }
}

elementBlocks solveMinMax (vector<vector<int>>& dataSet, int low, int high)
{
    elementBlocks tempResBlock;

    if(low == high)
    {
        tempResBlock = findminmaxFunc(dataSet[low], 0, (dataSet[low].size() - 1), low);
        return tempResBlock;
    }
    if(high - low == 1)
    {
        elementBlocks varOne = findminmaxFunc(dataSet[low], 0, (dataSet[low].size() - 1), low);
        elementBlocks varTwo = findminmaxFunc(dataSet[high], 0, (dataSet[high].size() - 1), high);

        if(varOne.max_score > varTwo.max_score)
        {
            Comparisons++;
            tempResBlock.max_score = varOne.max_score;
            tempResBlock.max_dept_index = varOne.max_dept_index;
        }
        else
        {
            Comparisons++;
            tempResBlock.max_score = varTwo.max_score;
            tempResBlock.max_dept_index = varTwo.max_dept_index;
        }

        if(varOne.min_score < varTwo.min_score)
        {
            Comparisons++;
            tempResBlock.min_score = varOne.min_score;
            tempResBlock.min_dept_index = varOne.min_dept_index;
        }
        else
        {
            Comparisons++;
            tempResBlock.min_score = varTwo.min_score;
            tempResBlock.min_dept_index = varTwo.min_dept_index;
        }

        return tempResBlock;
    }
    else
    {
        int mid = (high + low)/2;

        elementBlocks leftSide = solveMinMax(dataSet, low, mid);
        elementBlocks rightSide = solveMinMax(dataSet, mid+1, high);

        //combine
        tempResBlock = combineBlocks(leftSide, rightSide);

        return tempResBlock;
    }
}

int main()
{
    vector<vector<int>> departments = {{78, 85, 92, 67},{88, 76, 95, 82},{70, 88, 79, 91}};

    elementBlocks resultBlock = solveMinMax(departments, 0, (departments.size()-1));

    cout << "Highest Score: " << resultBlock.max_score << "\nDepartment: " << resultBlock.max_dept_index << "\nLowest Score: " << resultBlock.min_score << "\nDepartment: " << resultBlock.min_dept_index << "\nTotal Comparisons: " << Comparisons << " times" << endl;

    return 0;
}

//https://www.ideone.com/ztRGYe