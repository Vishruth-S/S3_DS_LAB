//Design a method for keeping two stacks within a single linear array so that neither stacks overflow until all the memory is used, 
//(one grows from one side of the array and the other grows from the other side). 
//Write all operations of stacks. eg. PUSH(S,x) that pushes element x onto stack S, where is S one or other of these two stacks.
// Include all necessary error checks.


int top1=-1,s;
int const max=10;
int top2;
top2=max;
void push(int stack[],int e)
{
    if(s==1)
    {
        if(top1==top2-1)
            printf("Stack1 full");
        else{
            top1++;
            stack[top1]=e;
        }
    }
    else
    {
        if(top2==top1+1)
            printf("Stack2 full");
        else{
            top2--;
            stack[top2]=e;
        }
    }
}

void pop(int stack[])
{
    
    if(s==1)
    {
        if(top1==-1)
            printf("Stack1 empty");
        else
        {
            printf("The popped element is %d",stack[top1]);
            top1--;
        }
    }
    else
    {
        if(top2==max-1)
            printf("Stack2 empty");
        else{
            printf("The popped element is %d",stack[top2]);
            top2++;
        }
    }
}
void display(int stack[])
{
    if(s==1)
    {
        printf("\nThe Stack1 is\n");
        for(int i=top1;i>=0;i--)
            printf("%d\n",stack[i]);
    }
    else
    {
        printf("\nThe Stack2 is\n");
        for(int i=max-1;i>=top2;i--)
            printf("%d\n",stack[i]);
    }
}
void main()
{
    int stack[10],n,ch,e;
    char ch1;
    ch1='y'; 
    while(ch1=='y')

    {
        printf("Do you want to insert into stack 1 or stack 2");
        scanf("%d",&s);
        printf("\n1.Push\n2.Pop\n3.Display");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter the element you have to push");
            scanf("%d",&e);
            push(stack,e);
            display(stack);
        }
        if(ch==2)
        {
            pop(stack);
            display(stack);
        }
    
    }

}