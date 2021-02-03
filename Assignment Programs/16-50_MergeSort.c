#include <stdio.h>
#include <string.h>

void merge(char str[], int lb, int mid, int ub)
{
    int Lsize = mid - lb + 1; // size of left stray
    int Rsize = ub - mid;     // size of right stray

    char leftstr[Lsize], rightstr[Rsize];

    for (int i = 0; i < Lsize; i++) // filling up the left arrray
        leftstr[i] = str[i + lb];

    for (int i = 0; i < Rsize; i++) // filling up the right array
        rightstr[i] = str[i + mid + 1];

    int i = 0, j = 0, k = lb;

    while (i < Lsize && j < Rsize) // inserting elements in sorted order
    {
        if (leftstr[i] < rightstr[j])
            str[k++] = leftstr[i++];
        else
            str[k++] = rightstr[j++];
    }

    while (i < Lsize) // for any remaining elements in left array
        str[k++] = leftstr[i++];

    while (j < Rsize) // for any remaining elements in right arrray
        str[k++] = rightstr[j++];
}

void mergesort(char str[], int lb, int ub)
{
    if (lb >= ub)
        return;

    int mid = (lb + ub) / 2;

    mergesort(str, lb, mid);
    mergesort(str, mid + 1, ub);
    merge(str, lb, mid, ub);
}

int main()
{
    char str[] = "POLYNOMIAL";
    int n = strlen(str);
    printf("\nOriginal String\n%s", str);
    mergesort(str, 0, n - 1);
    printf("\n\nAfter sorting\n%s\n", str);

    return 0;
}