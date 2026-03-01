#include <iostream>

using namespace std;

int arraySize;

void printArray(int array[])
{
    int index = 0;
    while(index < arraySize)
    {
        cout << array[index] << " ";
        index++;
    }
}

void Marge(int array[], int low, int mid, int high)
{
    int i = low;
    int j = mid+1;

    int temporaryArray[arraySize];
    int tempIndex = low;

    //conquer
    while(i <= mid && j <= high)
    {
        if(array[i] < array[j])
        {
            temporaryArray[tempIndex] = array[i];
            i++;
            tempIndex++;
        }
        else
        {
            temporaryArray[tempIndex] = array[j];
            j++;
            tempIndex++;
        }
    }
    if(i > mid)
    {
        int index = j;
        while(index <= high)
        {
            temporaryArray[tempIndex] = array[index];
            index++;
            tempIndex++;
        }
    }
    else
    {
        int index = i;
        while(index <= mid)
        {
            temporaryArray[tempIndex] = array[index];
            index++;
            tempIndex++;
        }
    }
    
    //transfer to main array
    int index = low;
    while(index <= high)
    {
        array[index] = temporaryArray[index];
        index++;
    }
}

void MargeSort(int array[], int low, int high)
{
    if(low < high)
    {
        int mid = (low+high)/2;

        //divide
        MargeSort(array, low, mid);    //left divide
        MargeSort(array, mid+1, high); //right divide

        //conquer
        Marge(array, low, mid, high);
    }
}

int main()
{
    cout << "Enter the array size: ";
    cin >> arraySize;

    int array[arraySize];
    
    int index = 0;
    while(index < arraySize)
    {
        cout << "Enter the element for index " << index << " : ";
        cin >> array[index];
        index++;
    }

    //initialization
    int low = 0;
    int high = arraySize-1;

    //calling marge-sort
    MargeSort(array, low, high);

    //printing the sorted array
    cout << "Sorted Array: ";
    printArray(array);

    return 0;
}