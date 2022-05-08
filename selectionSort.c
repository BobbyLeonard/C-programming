#include <stdio.h>

void printArray(int arr[], int arrLen);

int main(void)
{
    // set these as input
    int arr[] = {5, 3, 10, -1, 333, 4, 8, 5, 1, 7, 5, 9, 2, 6, 0, -1};
    int arrLen = 16;

    const int startArrLen = arrLen;

    // print the initial, unsorted array
    printArray(arr, startArrLen); 
    
    for (int i = 0; i < startArrLen - 1; i++)
    {
        // at start of loop, the value in index 0 will be first checked, therefore the smallest by default.
        int smallest = arr[0];
        int indexSmallest = 0;

        // loop through array to find the current smallest value
        for (int j = 0; j < arrLen; j++)
        {
            // compare array[j] with current smallest
            if (arr[j] < smallest)
            {
                smallest = arr[j];
                indexSmallest = j;
            }
        }        
        
        // copy the value in the last position
        int swapValue = arr[arrLen - 1];
        // swap the values, smallest to the end of the array
        arr[arrLen - 1] = smallest;
        arr[indexSmallest] = swapValue;
        // decrease array length by 1 to ignore this smallest value next loop
        arrLen--;

    }
    // print the final, sorted array
    printArray(arr, startArrLen);    
}

void printArray(int arr[], int arrLen)
{
    for (int j = 0; j < arrLen; j++)
    {
        printf("%i ", arr[j]);
    }
    printf("\n");
}
