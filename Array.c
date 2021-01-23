#include <stdio.h>
void Create(int a[],int);
void Display(int a[],int);
void Delete(int a[],int,int);
void Insert(int a[],int,int,int);
int array[20],n,i,c,p,e,t;
void main()
{
	while (1)
	{
		printf("\n_________Menu__________ \n");
		printf("Create\t:\t1\nInsert\t:\t2\nDisplay\t:\t3\nDelete\t:\t4\nExit\t:\t5");
		printf("\n______________________\n");
		printf("\nEnter The Choice 1 to 5:");
		scanf("%d", &c);
		if (c == 1)
		{
			printf("Enter The Number Of Elements:");
			scanf("%d", &n);
			Create(array, n)e
		}
		else if (c == 2)
		{
			printf("Enter The Position to be insert:");
			scanf("%d", &p);
			printf("Enter The Element Need to insert:");
			scanf("%d", &e);
			Insert(array, p, e, n);
			n++;
		}
		else if (c == 3)
			Display(array, n);
		else if (c == 4)
		{
			printf("Enter The Position to be Delete:");
			scanf("%d", &p);
			Delete(array, p, n);
			n--;
		}
		else if (c == 5)
			break;
		else
			printf("Invalid choice Tryagain");
	}
}
void Create(int a[], int n)
{
	for (i = 0; i < n; i++)
	{
		printf("Enter The Elament %d:", i + 1);
		scanf("%d", &a[i]);
	}
}
void Insert(int a[], int p, int e, int n)
{
	p--;
	n--;
	for (i = n; i >= 0; i--)
	{
		a[i + 1] = a[i];
		if (p == i)
		{
			a[i] = e;
			break;
		}
	}
}

void Display(int a[], int n)
{
	printf("\n");
	for (i = 0; i < n; i++)
		printf("%d\t", a[i]);
}
void Delete(int a[], int p, int n)
{
	p--;
	for (i = p; i < n; i++)
		a[i] = a[i + 1];
}
