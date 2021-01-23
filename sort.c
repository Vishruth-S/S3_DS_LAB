#include <stdio.h>
void Display(int a[], int);
void Get(int a[], int);
void bubble_sort(int a[], int);
void ins(int a[], int);
void sel(int a[], int);
int main()
{
	int Array[30], count, x;
L2:
	printf("Enter The Number Of Elaments:");
	scanf("%d", &count);
	printf("Enter The List Elaments\n");
	Get(Array, count);
	Display(Array, count);
	printf("\n1\t:\tbubble_sortble Sort\n2\t:\tInsertion Sort\n3\t:\tSelaction\n");
L1:
	printf("\nEnter The Search Choice:");
	scanf("%d", &x);
	if (x == 1)
	{
		bubble_sort(Array, count);
		printf("Sorted Array");
		Display(Array, count);
	}
	else if (x == 2)
	{
		ins(Array, count);
		printf("Sorted Array");
		Display(Array, count);
	}
	else if (x == 3)
	{
		sel(Array, count);
		printf("Sorted Array");
		Display(Array, count);
	}
	else
	{
		printf("Invalid Choice TryAgain");
		goto L1;
	}

	printf("\nEnter 1 to Continue: ");
	scanf("%d", &x);
	if (x == 1)
		goto L2;
}

void Get(int a[], int n)
{
	int i, el;
	for (i = 0; i < n; i++)
	{
		printf("Enter The %d th Elament :", i + 1);
		scanf("%d", &el);
		a[i] = el;
	}
}
void Display(int a[], int n)
{
	int i;
	printf("\n");
	for (i = 0; i < n; i++)
		printf("%d\t", a[i]);
}
void bubble_sort(int a[], int n)
{
	int i, j, t;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[i] > a[i + 1])
			{
				t = a[i + 1];
				a[i + 1] = a[i];
				a[i] = t;
			}
		}
	}
}
void ins(int a[], int n)
{
	int i, j, t1, t2, x;
	for (i = 0; i < n - 1; i++)
	{
		if (a[i] > a[i + 1])
		{
			j = 0;
			x = i + 1;
			while (x >= j)
			{
				if (a[j] < a[x])
					j++;
				else
				{
					t1 = a[j];
					a[j] = a[x];
					j++;
					while (j <= x)
					{
						t2 = a[j];
						a[j] = t1;
						t1 = t2;
						j++;
					}
				}
			}
		}
	}
}

void sel(int a[], int n)
{
	int min, i, j, t;
	for (i = 0; i < n; i++)
	{
		min = i;
		for (j = i; j < n; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		if (min != i)
		{
			t = a[min];
			a[min] = a[i];
			a[i] = t;
		}
	}
}
