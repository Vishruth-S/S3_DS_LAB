//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 5 QUESTION 2
//Program to implement Insertion Sort

#include <stdio.h>

void insertionSort(int arr[], int size) // Time complexity: O(n^2)
{
    int j, temp;
    for (int i = 1; i < size; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && temp < arr[j]) // if elements greater than temp
        {
            arr[j + 1] = arr[j]; // shift them to the right
            j--;
        }
        arr[j + 1] = temp; // and insert temp at this position
    }
}

int main()
{
    int arr[100], size;
    printf("\nEnter size ");
    scanf("%d", &size);
    printf("\nEnter array\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    insertionSort(arr, size);

    printf("Sorted array\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}