//Question No:13 :Write a C program to implement linear queue using array

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int front=-1,rear=-1,Max=5;

bool isfull()
{	if(rear==Max-1)
		return true;
	else
		return false;
}

bool isempty()
{	if(front<0 || front>rear)
		return true;
	else
		return false;
}
						
void enqueue(int queue[5],int term)
{	if(isfull())
		printf("Queue is full\n");
	else
	{	if(isempty())
			front=rear=0;
		else	
			rear++;
		queue[rear]=term;
	}
}

int dequeue(int queue[5])
{	int term;	
	if(isempty())
		return 0;
		else
		{	term=queue[front];
			front++;
			return term;
		}
}

void display(int queue[5])
{	if(isempty())
		printf("Queue is empty\n");
	else	
	{	printf("Elements in queue:\n");
		for(int i=front;i<=rear;i++)
			printf("%d\t",queue[i]);
	}		
}		

void main()
{
int queue[5],ch,term;
bool check;
do{	printf("\nMENU");
	printf("\n1.Insert element");
	printf("\n2.Delete element");
	printf("\n3.Display elements in queue");
	printf("\n4.Check if queue is empty");
	printf("\n5.Check if queue is full");
	printf("\n6.Exit");
	printf("\nEnter choice :");
	scanf("%d",&ch);
	switch(ch)
	{	case 1:printf("Enter element to be added to stack  \n");
			scanf("%d",&term);
			enqueue(queue,term);
			break;
		case 2:term=dequeue(queue);
			if(term==0)
				printf("The stack is empty\n");
			else
				printf("The Deleted element is %d\n",term);	
			break;
		case 3:display(queue);
			break;
		case 4:check=isempty();
			if(check==true)
				printf("Queue is empty\n");
			else
				printf("Queue is not empty\n");
			break;
		case 5:check=isfull();
			if(check==true)
				printf("Queue is full\n");
			else
				printf("Queue is not full\n");
			break;
		case 6:						
		default:exit(0);
	}
}while(ch<7);		
}			
