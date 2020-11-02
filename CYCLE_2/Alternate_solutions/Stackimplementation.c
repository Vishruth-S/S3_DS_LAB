// Write a C program to implement a stack using array
// Done by Elizabeth Mathew

#include<stdio.h>


int top=-1;
int max=5;
void push(int stack[],int e)
{
    if(top==max-1)
        printf("stack full");
    else{
        top++;
        stack[top]=e; 
    }
    
}
int isempty()
{
    if(top==-1)
        return 1;
    return 0;
}

void pop(int stack[])
{
    if(!isempty())
    {
        printf("Popped element is:%d\n",stack[top]);
        top--;
    }
    else
    {
        printf("Stack is empty");
    }
}
void peek(int stack[])
{
    printf("%d", stack[top]);
}
void display(int stack[])
{
    printf("\nThe Stack is\n");
    for(int i=top;i>=0;i--)
        printf("%d\n",stack[i]);
}
void main()
{
    int stack[5],ch=5,e;
    do{
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter the element you have to push");
            scanf("%d",&e);
            push(stack,e);
        }
        if(ch==2)
        {
            pop(stack);
            display(stack);
        }
         if(ch==3)
        {
            peek(stack);
        } 
        if(ch==4)
        {
            display(stack);
        }
    }while(ch<=4)
}
