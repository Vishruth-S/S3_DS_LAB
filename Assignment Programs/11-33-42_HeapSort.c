// Sort the sequence of letters E,X,A,M,P,L,E using Heap Sort

#include <stdio.h>
#include <string.h>

void swap(char *x, char *y)
{
    char t = *x;
    *x = *y;
    *y = t;
}

// Time complexity: O(n)
void heapify(char arr[], int n, int i)
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

// Time complexity: O(nlogn)
void heapsort(char arr[], int n)
{
    // Build max-heap by heapifying the array
    for (int i = n / 2; i >= 0; i--)
        heapify(arr, n, i);

    // one by one extract the top from the heap
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]); // and move it to the end
        heapify(arr, i, 0);     // heapify the reduced heap
    }
}

int main()
{
    char s[] = {'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    int n = strlen(s);
    printf("Original array\n");
    for (int i = 0; i < n; i++)
        printf("%c ", s[i]);

    heapsort(s, n);
    printf("\nSorted array\n");
    for (int i = 0; i < n; i++)
        printf("%c ", s[i]);
    return 0;
}