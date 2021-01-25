//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 5 QUESTION 1
//Program to implement Selection Sort

#include <stdio.h>

void selectionSort(int arr[], int size) // Time complexity: O(n^2)
{
    int minIndex, temp;
    for (int i = 0; i < size; i++) // move starting point of unsorted array one-by-one
    {
        minIndex = i;
        for (int j = i + 1; j < size; j++) // find the minimum in unsorted array
            if (arr[j] < arr[minIndex])
                minIndex = j;

        temp = arr[minIndex]; // swap minimum with first element
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[100], size;
    printf("\nEnter size ");
    scanf("%d", &size);
    printf("\nEnter Array "); 
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    selectionSort(arr, size);  

    printf("Sorted Array: \n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}