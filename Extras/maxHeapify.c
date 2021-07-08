// Program to convert an array into a max heap by using Heapify method.

#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void maxHeapify(int arr[], int i, int n)
{
    int largest = i;
    int leftChild = (2 * i) + 1;
    int rightChild = (2 * i) + 2;
    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;
    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, largest, n);
    }
}

// Time complexity: O(n)
void makeHeap(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
        maxHeapify(arr, i, n);
}

int main()
{
    int n;
    int arr[1000];
    printf("Enter size of array\n");
    scanf("%d", &n);
    printf("Enter array elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    makeHeap(arr, n);
    printf("\nMax heap\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}