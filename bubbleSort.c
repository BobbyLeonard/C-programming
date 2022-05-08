#include <stdio.h>

void printArray(int arr[], int arrLen);

int main(void)
{
    // Set these as input
    int arr[] = {5, 3, 10, -1, 333, 4, 8, 5, 1, 7, 5, 9, 2, 6, 0, -1};
    int arrLen = 16;

    int startArrLen = arrLen;
    // print the initial, unsorted array
    printArray(arr, startArrLen); 
    
    int swapsThisLoop = -1;
    for (int i = 0; i < startArrLen - 1; i++)
    {
        if (swapsThisLoop != 0)
        {
            swapsThisLoop = 0;
            for (int j = 0; j < arrLen - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int holdLesser = arr[j + 1];
                    int holdGreater = arr[j];
                    arr[j + 1] = holdGreater;
                    arr[j] = holdLesser;
                    swapsThisLoop++;
                }
                
            }
            // decrement the size of the array to ignore the smallest element next loop
            arrLen--;
        }

        // else if there are no swaps this time, sort is complete, print the final, sorted array and exit
        else
        {
            printArray(arr, startArrLen);
            return 0;
        }

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
