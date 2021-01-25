//Write a C program to implement a queue using array
// By Elizabeth Mathew


#include<stdio.h>
int rear=-1,front=-1;
int max=5;

int isfull() 
{
    if(rear==max-1)
        return 1;
    return 0;
}
int isempty()
{
    if(front==-1||front>rear)
        return 1;
     return 0;
}

void enq(int q[],int e)
{
    if(isfull())
        printf("Queue full");
    else if(rear==-1)
    {
        rear++;
        front++;
        q[rear]=e;
    }
    else{
        rear++;
        q[rear]=e;
    }
    
}

void deq(int q[])
{
    if(!isempty())
    {
        printf("Popped element is:%d\n",q[front]);
        front++;
    }
    else
    {
        printf("Queue is empty");
    }
    
    
}

void display(int q[])
{
    printf("\nThe Queue is\n");
    for(int i=rear;i>=front;i--)
        printf("%d\n",q[i]);
}

void main()
{
     int q[5],ch=4,e;
    do {
        printf("\n1.Push\n2.Pop");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter the element you have to push");
            scanf("%d",&e);
            enq(q,e);
        }
        if(ch==2)
        {
            deq(q);
        }
        if(ch==3)
        {
            display(q);
        }
    } while(ch<=3);
}
