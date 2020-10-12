// ====PROGRAM FOR LINEAR SEARCH IN ARRAY USING RECURSION==== //

#include <stdio.h>

int linearSearch(int arr[], int n, int value, int index)
{
    int pos = -1;
    if (index >= n)
        return -1;
    else if (arr[index] == value)
    {
        pos = index;
        return pos;
    }
    else
        return linearSearch(arr, n, value, index + 1);
    return pos;
}

int main()
{
    int a[1000], n, i;
    printf("\nEnter number of elements ");
    scanf("%d", &n);
    printf("\nEnter array elements ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int element, ind;
    printf("\nEnter element to be searched: ");
    scanf("%d", &element);
    ind = linearSearch(a, n, element, 0);
    if (ind != -1)
        printf("\nElement found at index: %d", ind);
    else
        printf("\nElement doesn't exist in array");
    return 0;
}
