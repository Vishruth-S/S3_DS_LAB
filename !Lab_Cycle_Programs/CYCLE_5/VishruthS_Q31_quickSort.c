//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 5 QUESTION 3
//Program to implement Quick Sort

#include <stdio.h>

// function to swap 2 elements
void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

// Partition function
int partition(int arr[], int left, int right)
{
    int pivot = arr[right]; // pivot element
    int pIndex = left;      // smaller index

    for (int i = left; i < right; i++)
    {
        if (arr[i] < pivot)                // if current element is less than pivot
            swap(&arr[i], &arr[pIndex++]); // swap and incerement smaller index
    }
    swap(&arr[pIndex], &arr[right]); // swap smaller index with pivot

    return pIndex;
}

void quickSort(int arr[], int left, int right)
{
    if (left >= right) // base case to exit recursion
        return;

    int pIndex = partition(arr, left, right); // find pivot
    quickSort(arr, left, pIndex - 1);         // sort elements left of pivot
    quickSort(arr, pIndex + 1, right);        // sort elements right of pivot
}

int main()
{
    int arr[100], size;
    printf("\nEnter size ");
    scanf("%d", &size);
    printf("\nEnter array ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}