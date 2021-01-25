// Iterative Heap Sort

#include <stdio.h>

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

// Time complexity: O(nlogn)
void makeHeap(int arr[], int n)
{
    for (int j = 0; j < n; j++)
    {
        int data = arr[j];
        int i = j;
        while (i && data > arr[i / 2])
        {
            swap(&arr[i / 2], &arr[i]);
            i /= 2;
        }
    }
}

// Time complexity: O(nlogn)
void HeapSort(int arr[], int n)
{
    for (int j = n - 1; j > 0; j--)
    {
        swap(&arr[0], &arr[j]);
        int i = 0, lc, rc;
        lc = 2 * i + 1;
        rc = 2 * i + 2;
        while (rc < j && (arr[i] < arr[lc] || arr[i] < arr[rc]))
        {
            if (arr[rc] > arr[lc])
            {
                swap(&arr[i], &arr[rc]);
                i = rc;
            }
            else
            {
                swap(&arr[i], &arr[lc]);
                i = lc;
            }
            lc = 2 * i + 1;
            rc = 2 * i + 2;
        }
    }
}

int main()
{

    int arr[] = {45, 33, 35, 12, 16, 24, 34, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    makeHeap(arr, n);
    printf("\nBefore sorting\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    HeapSort(arr, n);
    printf("\n\nAfter sorting\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}