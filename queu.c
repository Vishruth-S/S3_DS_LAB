#include <stdio.h>
#define Max_Size 50
void Eq(int Q[],int,int *F,int *R);
void Dq(int Q[],int *F,int *R);
void Display(int Q[],int *F,int *R);
int FRONT=0,x,Queu[Max_Size],R,Item;
int main()
{
	R=0;	
	while (1)
	{
		printf("\n_________Queue_________\n");
		printf("1\t:\tEnqueue\n2\t:\tDequeue\n3\t:\tDisplay\n0\t:\tExit\nEnter The Choice:");
		scanf("%d", &x);
		if (x == 1)
		{
			printf("\nEnter The Item:");
			scanf("%d", &Item);
			Eq(Queu,Item,&FRONT,&R);
		}		
		else if (x ==2)					
			Dq(Queu,&FRONT,&R);
		else if (x==3)
			Display(Queu,&FRONT,&R);
		else if (x==0)
			break;
		else 
			printf("Invalid choice tryagain\n");

	}
}
void Eq(int Q[],int x,int *F,int *R)
{
	int rear;
	rear=*R;	
	if (rear == Max_Size)
		printf("Queue is full");
	else
	{
		if ((rear==0) && (*F==0))
			*F=1;		
		rear++;
		Q[rear]=x;
		*R=rear;		
	}
	
}
void Dq(int Q[],int *F,int *R)
{
	int rear,Item;
	rear=*R;		
	if (rear == 0)
	{
		printf("Queue is empty");
		*F=0;
	}		
	else
	{
		Item = Q[rear];
		*F=*F+1;	
	}
}
void Display(int Q[],int *F,int *R)
{
	int i;
	if (*R == 0)
		printf("\nQueue  is Empty\n");
	else
	{
		printf("\nElaments In Queue are:\n");
		for (i = *F; i <= *R ; i++)
			printf("%d\n", Q[i]);
	}
}



