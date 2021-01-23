#include <stdio.h>
#define Max_Size 5
void Push();
void Pop();
void Isempty();
void Isfull();
void Display();
int stack[Max_Size], Top = -1, x;
void main()
{
	while (1)
	{
		printf("\n_________STACK_________\n");
		printf("1\t:\tPush\n2\t:\tPop\n3\t:\tIsempty\n4\t:\tIsfull\n5\t:\tDisplay\n0\t:\tExit\nEnter The Choice:");
		scanf("%d", &x);
		if (x == 1)
			Push();
		else if (x == 2)
			Pop();
		else if (x == 3)
			Isempty();
		else if (x == 4)
			Isfull();
		else if (x == 5)
			Display();
		else if (x==0)
			break;
		else 
			printf("Invalid choice tryagain\n");
	}
}
void Push()
{
	int Item;
	printf("\nEnter The Item:");
	scanf("%d", &Item);
	if (Top >= Max_Size)
		printf("\nStack Is Full");
	else
	{
		Top++;
		stack[Top] = Item;
	}
	printf("Elament %d Is added to stack", stack[Top]);
}
void Pop()
{
	int Item;
	if (Top == -1)
		printf("\nStack is Empty");
	else
	{
		Item = stack[Top];
		Top = Top - 1;
		printf("The  Elament %d is Poped", Item);
	}
}
void Isempty()
{
	if (Top == -1)
		printf("\nStack is Empty\n");
	else
		printf("\nStack is Notempty\n");
}
void Isfull()
{
	if (Top >= Max_Size)
		printf("\nStack Is Full");
	else
		printf("\nStack Is NotFull\n");
}
void Display()
{
	int i;
	if (Top == -1)
		printf("\nStack is Empty\n");
	else
	{
		printf("\nElaments In Stack are:\n");
		for (i = Top; i > -1; i--)
			printf("%d\n", stack[i]);
	}
}
