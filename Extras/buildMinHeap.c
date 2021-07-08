// Program to convert an array into a min heap, using simple heap insertion.

#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void insertIntoMinHeap(int arr[], int i)
{
    int curr = i;
    int parent = (curr - 1) / 2;
    while (parent >= 0 && arr[curr] < arr[parent])
    {
        swap(&arr[curr], &arr[parent]);
        curr = parent;
        parent = (curr - 1) / 2;
    }
}

// Time complexity: O(nlogn)
void makeHeap(int arr[], int n)
{
    for (int i = 1; i < n; i++)
        insertIntoMinHeap(arr, i);
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