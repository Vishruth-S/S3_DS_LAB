//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 5 QUESTION 5
//Program to implement Heap Sort

#include <stdio.h>

// function to swap 2 elements
void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

// ======== HEAPIFY - To make the heap ========= //
void heapify(int arr[], int n, int i) // Time complexity: O(n)
{
    int largest = i; // Initialize largest as root
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < n && arr[left] > arr[largest]) // if left child larger than root
        largest = left;
    if (right < n && arr[right] > arr[largest]) // if right child larger than root
        largest = right;
    if (largest != i) // if largest is not root
    {
        swap(&arr[i], &arr[largest]); // swap root and largest
        heapify(arr, n, largest);     // and recursively heapify that sub-tree
    }
}

// ============ HEAP SORT ============= //
void heapSort(int arr[], int n) // Time complexity: O(nlogn)
{
    for (int i = n / 2 - 1; i >= 0; i--) // Make the heap using heapify
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) // Take one element from heap
    {
        swap(&arr[0], &arr[i]); // and move current root to end
        heapify(arr, i, 0);     // call heapify on the reduced heap
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

    heapSort(arr, size);

    printf("\nSorted array\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}