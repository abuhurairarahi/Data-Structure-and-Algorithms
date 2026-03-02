#include <iostream>

using namespace std;

int arraySize;

void printArray(int array[])
{
    int index = 0;
    while (index < arraySize)
    {
        cout << array[index] << " ";
        index++;
    }
}

void swipe(int array[], int fromIndex, int toIndex)
{
    int temporaryVariable = array[fromIndex];
    array[fromIndex] = array[toIndex];
    array[toIndex] = temporaryVariable;
}

int pivotIndex(int array[], int low, int high)
{
    int pivot = high;
    int blueTracker = low - 1;
    int redTracker = low;

    while (redTracker < high)
    {
        if (array[redTracker] < array[pivot])
        {
            blueTracker++;
            swipe(array, redTracker, blueTracker);
            redTracker++;
        }
        else
        {
            redTracker++;
        }
    }

    // pivot placing
    blueTracker++;
    swipe(array, blueTracker, pivot);

    // pivot is shifted to blueTracker
    return blueTracker;
}

void QuickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pivotLocation = pivotIndex(array, low, high);
        QuickSort(array, low, pivotLocation - 1);
        QuickSort(array, pivotLocation + 1, high);
    }
}

int main()
{
    cout << "Enter the array size: ";
    cin >> arraySize;

    int array[arraySize];
    int index = 0;
    while (index < arraySize)
    {
        cout << "Enter element for index " << index << " : ";
        cin >> array[index];
        index++;
    }

    int low = 0;
    int high = arraySize - 1;

    QuickSort(array, low, high);

    printArray(array);

    return 0;

    /*
   
    Divide & Conquer (Quick-Sort):
    1. Divide  --> 2T(n/2) "for average-case"
    2. Conquer --> O(n)
    3. Combine --> O(1)

    Time Complexity: #AverageCase
    Marge-Sort & Binary-Tree have same kind of height --> (logn)
    Per-Level operation: n

    T(n) = Per-Level operation * total-height
         = n * logn
         = nlogn

    --> Average-case time-complexity: θ(nlogn)

    --> Worst-case time-complexity: O(n^2); 
    ##appears when the array is sorted!

    */
}