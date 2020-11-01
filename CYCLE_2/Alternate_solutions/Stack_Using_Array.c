//Question No:12 :Write a C program to implement a stack using array
//By Megha Mariam

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int top=-1,Max=5;

bool isempty()
{	if(top==-1)
		return true;
	return false;	
}

bool isfull()
{	if(top==Max-1)
		return true;
	return false;
}
			
void push(int stack[5],int term)
{	if(isfull())
		printf("Elements cannot be added as stack is full");
	else
	{
		top++;
		stack[top]=term;
	}
}
			
int pop(int stack[5])
{	int term;	
	if(isempty())
		return 0;
	else
	{
		term=stack[top];
		top--;
	}	
	return term;
}

int peek(int stack[5])
{
	if(isempty())
		return 0;
	else
		return stack[top];	
}	

void display(int stack[5])
{
	if(isempty())
		printf("\nStack is empty");
	else
	{	printf("\nElements in stack\n");
		for(int i=0;i<=top;i++)
			printf("%d\t",stack[i]);
	}
	printf("\n");
}							

void main()
{
int stack[5],ch,term;
bool check;

do{	printf("\nMENU");
	printf("\n1.Push element into the array");
	printf("\n2.Pop element of array");
	printf("\n3.Get the topmost element");
	printf("\n4.Display elements in stack");
	printf("\n5.Check if stack is empty");
	printf("\n6.Check if stack is full");
	printf("\n7.Exit");
	printf("\nEnter choice :");
	scanf("%d",&ch);
	switch(ch)
	{	case 1:printf("\nEnter element to be added to stack  ");
			scanf("%d",&term);
			push(stack,term);
			break;
		case 2:term=pop(stack);
			if(term==0)
				printf("\nThe stack is empty");
			else
				printf("The Deleted element is %d\n",term);	
			break;
		case 3:term=peek(stack);
			if(term==0)
				printf("\nEmpty stack");
			else
				printf("Top most element is %d\n",term);	
			break;
		case 4:display(stack);
			break;
		case 5:check=isempty();
			if(check==true)
				printf("\nStack is empty");
			else
				printf("\nStack is not empty");
			break;
		case 6:check=isfull();
			if(check==true)
				printf("\nStack is full");
			else
				printf("\nStack is not full");
			break;					
		default:exit(0);
	}
}while(ch<8);		
}			
