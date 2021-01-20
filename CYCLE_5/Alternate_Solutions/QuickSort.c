#include <stdio.h>

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

// Partition function
int partition(int arr[], int left, int right)
{
    int pivot = arr[left];
    int pIndex = left;
    while (left < right)
    {
        while (left < right && arr[left] <= pivot)
            left++;

        while (arr[right] > pivot)
            right--;

        if (left < right)
            swap(&arr[left], &arr[right]);
    }
    arr[pIndex] = arr[right];
    arr[right] = pivot;

    return right;
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
    printf("\nEnter array\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, size - 1);

    printf("\nSorted array\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}
