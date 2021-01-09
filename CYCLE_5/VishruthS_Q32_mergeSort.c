//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 5 QUESTION 4
//Program to implement Merge Sort

#include <stdio.h>

// Function to merge two sorted arrays
void merge(int arr[], int left, int right, int mid)
{
    int Lsize = mid - left + 1; // size of left array
    int Rsize = right - mid;    // size of right array

    int leftArr[Lsize], rightArr[Rsize];

    for (int i = 0; i < Lsize; i++) // filling up the left array
        leftArr[i] = arr[i + left];

    for (int i = 0; i < Rsize; i++) // filling up the right array
        rightArr[i] = arr[i + mid + 1];

    int i = 0, j = 0, k = left;

    while (i < Lsize && j < Rsize) // inserting elements in sorted order
    {
        if (leftArr[i] < rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }

    while (i < Lsize) // for any remaining elements in left array
        arr[k++] = leftArr[i++];

    while (j < Rsize) // for any remaining elements in right array
        arr[k++] = rightArr[j++];
}

void mergeSort(int arr[], int left, int right) // Time complexity: O(nlogn)
{
    if (left >= right) // base condition to exit recursion
        return;

    int mid = left + (right - left) / 2; // calculating mid, same as (left + right)/2

    mergeSort(arr, left, mid);      // perform mergesort on left half
    mergeSort(arr, mid + 1, right); // perform mergesort on right half
    merge(arr, left, right, mid);   // Merge the sorted arrays
}

int main()
{
    int arr[100], size;
    printf("\nEnter size ");
    scanf("%d", &size);
    printf("\nEnter array\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, size - 1);

    printf("Sorted array\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}