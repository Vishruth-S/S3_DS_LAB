// Max-heapify a given array

#include <stdio.h>

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

// Time complexity: O(n)
void heapify(int arr[], int n, int i)
{
    int largest = i;   // let largest be root
    int l = 2 * i + 1; // left child
    int r = 2 * i + 2; // right child

    //  If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l; // then update largest

    // If right child is larger than root
    if (r < n && arr[r] > arr[largest])
        largest = r; // then update largest

    // if largest is no longer the root
    if (largest != i)
    {
        swap(&arr[largest], &arr[i]); // swap with the root
        // and recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

int main()
{
    int arr[] = {16, 8, 10, 50, 15, 20, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    for (int i = n / 2; i >= 0; i--)
        heapify(arr, n, i);

    printf("\nMax heap\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}