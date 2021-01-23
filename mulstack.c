#include <stdio.h>
#include <string.h>
#include<math.h>
#define Max_Size 50
void PUSH(int a[],int x,int y ,int *TOP,int *END);
void POP(int a[],int *TOP,int *END);
void Isempty(int *TOP);
void Isfull(int *TOP,int *END);
void Display(int a[], int *TOP,int *END);
int main()
{
	int TOP = -1, END = Max_Size, length, stack[Max_Size],e1,e2,x;
	while (1)
	{
		printf("\n_________STACK_________\n");
		printf("1\t:\tPush\n2\t:\tPop\n3\t:\tIsempty\n");
		printf("4\t:\tIsfull\n5\t:\tDisplay\n0\t:\tExit\n");
		printf("Enter The Choice:");
		scanf("%d", &x);
		if (x == 1)
		{
			printf("Enter The Top Elament:");
			scanf("%d", &e1);
			printf("Enter The End Elament:");
			scanf("%d", &e2);
			PUSH(stack,e1,e2,&TOP,&END);
		}
		else if (x == 2)
		{
			POP(stack,&TOP,&END);
		}
		else if (x == 3)
		{		
			Isempty(&TOP);
		}		
		else if (x == 4)
		{		
			Isfull(&TOP,&END);
		}
		else if (x == 5)
		{
			Display(stack,&TOP,&END);
		}		
		else if (x == 0)
			break;
		else
			printf("Invalid choice tryagain\n");
	}

}
void PUSH(int a[],int x,int y ,int *TOP,int *END)
{
	int top,end;
	top=*TOP;
    	end=*END;	
	if (top == end)
		printf("\nStack Is Full");
	else
	{
		top++;
		end--;
		a[top] = x;
		a[end] = y;
		*TOP = top;
		*END = end;
	}
}
void POP(int a[],int *TOP,int *END)
{
	int top,end;
	top=*TOP;	
    	end=*END;
	if ( top==-1)
		printf("Stack Is Empty");
	else
	{
        printf("Top Elament %d and Ent Elamennt %d are POPED",a[top],a[end]);
	*TOP=*TOP-1;		
        *END=*END+1;
	}
}
void Isempty(int *TOP)
{
	if (*TOP == -1)
		printf("Stack Is Empty");
	else 
		printf("Stack Is Not Empty");
}
void Isfull(int *TOP,int *END)
{
	if (*TOP == *END)
		printf("Stack Is Full");
	else
		printf("Stack Is Not Full");
}
void Display(int a[],int *TOP,int *END)
{
	int i;
	for (i = 0; i <= *TOP ; i++)
		printf("\n%d", a[i]);
	for (i =*END ; i <Max_Size ; i++)
		printf("\n%d", a[i]);
}
