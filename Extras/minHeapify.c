// Program to convert an array into a min heap by using Heapify method.

#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void minHeapify(int arr[], int i, int n)
{
    int smallest = i;
    int leftChild = (2 * i) + 1;
    int rightChild = (2 * i) + 2;
    if (leftChild < n && arr[leftChild] < arr[smallest])
        smallest = leftChild;
    if (rightChild < n && arr[rightChild] < arr[smallest])
        smallest = rightChild;
    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, smallest, n);
    }
}

// Time complexity: O(n)
void makeHeap(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
        minHeapify(arr, i, n);
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
    printf("\nMin heap\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}