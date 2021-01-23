#include <stdio.h>
#include <malloc.h>
#include<conio.h>
struct node
{
	int EXP;
	int COEFF;
	struct node *link;
} * Rh, *Ph, *Qh, *Pptr, *Qptr, *Rptr, *newptr,*ptr;
int main()
{
	int i, p, q, exp, coeff, f = 0;
	Ph = (struct node *)malloc(sizeof(struct node));
	Qh = (struct node *)malloc(sizeof(struct node));
	Ph->link = NULL;
	Qh->link = NULL;
	Pptr = Ph;
	Qptr = Qh;
	printf("Enter The Number of Terms in P:");
	scanf("%d", &p);
	printf("\nInput The Polynomial P\n");
	for (i = 0; i < p; i++)
	{
		newptr = (struct node *)malloc(sizeof(struct node));
		printf("Enter The %d th EXP:", i + 1);
		scanf("%d", &exp);
		newptr->EXP = exp;
		printf("Enter The %d th COEFF:", i + 1);
		scanf("%d", &coeff);
		newptr->COEFF = coeff;
		newptr->link = NULL;
		Pptr->link = newptr;
		Pptr = newptr;
	}
	Pptr = Ph->link;
	printf("\nThe Polynomial P:");
	do
	{
		printf("%dX^%d ", (Pptr->COEFF), (Pptr->EXP));
		if (Pptr->link != NULL)
			printf(" + ");
		Pptr = Pptr->link;
	} while (Pptr != NULL);

	printf("\nInput The Number of Terms in Q:");
	scanf("%d", &q);
	printf("Enter The Polynomial Q\n");
	for (i = 0; i < q; i++)
	{
		newptr = (struct node *)malloc(sizeof(struct node));
		printf("Enter The %d th EXP:", i + 1);
		scanf("%d", &exp);
		newptr->EXP = exp;
		printf("Enter The %d th COEFF:", i + 1);
		scanf("%d", &coeff);
		newptr->COEFF = coeff;
		newptr->link = NULL;
		Qptr->link = newptr;
		Qptr = newptr;
	}
	Qptr = Qh->link;
	printf("\nThe Polynomial Q:");
	do
	{
		printf("%dX^%d", (Qptr->COEFF), (Qptr->EXP));
		if (Qptr->link != NULL)
			printf(" + ");
		Qptr = Qptr->link;
	} while (Qptr != NULL);

	Rh = (struct node *)malloc(sizeof(struct node));
	Rh->link = NULL;
	Rptr = Rh;
	Pptr = Ph->link;
	Qptr = Qh->link;
	while (Pptr != NULL && Qptr != NULL)
	{
		if (Pptr->EXP == Qptr->EXP)
		{
			newptr = (struct node *)malloc(sizeof(struct node));
			Rptr->link = newptr;
			Rptr = newptr;
			Rptr->COEFF = (Pptr->COEFF) + (Qptr->COEFF);
			Rptr->EXP = Pptr->EXP;
			Rptr->link = NULL;
			Pptr = Pptr->link;
			Qptr = Qptr->link;
		}
		else if (Pptr->EXP > Qptr->EXP)
		{
			newptr = (struct node *)malloc(sizeof(struct node));
			Rptr->link = newptr;
			Rptr = newptr;
			Rptr->COEFF = Pptr->COEFF;
			Rptr->EXP = Pptr->EXP;
			Pptr = Pptr->link;
		}
		else if (Pptr->EXP < Qptr->EXP)
		{
			newptr = (struct node *)malloc(sizeof(struct node));
			Rptr->link = newptr;
			Rptr = newptr;
			Rptr->COEFF = Qptr->COEFF;
			Rptr->EXP = Qptr->EXP;
			Qptr = Qptr->link;
		}
	}
	if (Pptr != NULL && Qptr == NULL)
	{
		newptr = (struct node *)malloc(sizeof(struct node));
		Rptr->link = newptr;
		Rptr = newptr;
		Rptr->COEFF = Pptr->COEFF;
		Rptr->EXP = Pptr->EXP;
		Pptr = Pptr->link;
	}
	if (Pptr == NULL && Qptr != NULL)
	{
		newptr = (struct node *)malloc(sizeof(struct node));
		Rptr->link = newptr;
		Rptr = newptr;
		Rptr->COEFF = Qptr->COEFF;
		Rptr->EXP = Qptr->EXP;
		Qptr = Qptr->link;
	}
	Rptr = Rh->link;
	printf("\nSum Of Polynomial:");
	do
	{
		printf("%dX^%d", (Rptr->COEFF), (Rptr->EXP));
		if (Rptr->link != NULL)
			printf(" + ");
		Rptr = Rptr->link;
	} while (Rptr != NULL);
	Rh->link = NULL;
	Rptr = Rh;
	Pptr = Ph;
	while (Pptr->link != NULL)
	{
		Qptr = Qh->link;
		Pptr = Pptr->link;
		while (Qptr != NULL)
		{
			exp = (Pptr->EXP) + (Qptr->EXP);
			coeff = (Pptr->COEFF) * (Qptr->COEFF);
			ptr=Rptr;
			if (Rptr->link == NULL)
			{
				newptr = (struct node *)malloc(sizeof(struct node));
				newptr->COEFF = coeff;
				newptr->EXP = exp;
				Rptr->link = newptr;
				newptr->link = NULL;
				Qptr = Qptr->link;
				Rptr = Rh;
			}
			else
				Rptr = Rptr->link;
			if ((Rptr->EXP) == exp)
			{
				Rptr->COEFF = Rptr->COEFF + coeff;
				Qptr = Qptr->link;
				Rptr = Rh;
			}
		}
	}
	Rptr = Rh->link;
	printf("\nThe Polynomial Multiplication:");
	do
	{
		printf("%dX^%d", (Rptr->COEFF), (Rptr->EXP));
		if (Rptr->link != NULL)
			printf(" + ");
		Rptr = Rptr->link;
	} while (Rptr != NULL);
	printf("\n");
	getch();
	getch();
getch();
}
