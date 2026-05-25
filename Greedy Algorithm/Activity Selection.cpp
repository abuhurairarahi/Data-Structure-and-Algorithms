#include <bits/stdc++.h>

using namespace std;

struct activityInfo
{
    int serial;
    int startTime;
    int endTime;
};

struct returnInfo
{
    vector<activityInfo> selectedActivities;
    int taskCount;
};

bool comparator(activityInfo activityA, activityInfo activityB)
{
    int endtimeOne = activityA.endTime;
    int endtimeTwo = activityB.endTime;

    return endtimeOne < endtimeTwo;
}

returnInfo activitySelection(vector<activityInfo> &dataSet)
{
    sort(dataSet.begin(), dataSet.end(), comparator); //sorted in ascending order basis on endTime

    returnInfo finalInfo;
    int selectedTask_Index = 0;
    int countTask = 1;

    finalInfo.selectedActivities.push_back(dataSet[0]);

    for(int index = 1; index < dataSet.size(); index++)
    {
        if(dataSet[selectedTask_Index].endTime < dataSet[index].startTime)
        {
            countTask += 1;
            selectedTask_Index = index;
            finalInfo.selectedActivities.push_back(dataSet[index]);
        }
    }

    finalInfo.taskCount = countTask;

    return finalInfo;
}

int main()
{
    int size;
    cout << "Enter the number of activities: " ;
    cin >> size;

    vector<activityInfo> dataSet(size);
    
    int index = 0;
    while(index < size)
    {
        cout << "For activity " << index+1 << endl;
        
        dataSet[index].serial = index+1;

        cout << "Enter the start time: ";
        cin >> dataSet[index].startTime;
        
        cout << "Enter the end time: ";
        cin >> dataSet[index].endTime;

        index++;
    }

    returnInfo finalSelection = activitySelection(dataSet);

    cout << "Total Selected Task: " << finalSelection.taskCount << endl;

    for(activityInfo x : finalSelection.selectedActivities)
    {
        cout << "Selected Task: " << x.serial << " --> Start Time: " << x.startTime << " End Time: " << x.endTime << endl;
    }

    return 0;
}