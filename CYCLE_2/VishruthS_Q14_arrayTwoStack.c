#include <stdio.h>

#define MAX 20

int Dstack[MAX];           // Single array for two stacks
int top1 = -1, top2 = MAX; // For 2 stacks

// Push function to insert element
void push(int stackNumber, int el)
{
    if (stackNumber == 1) // For stack 1
    {
        if (top1 == top2 - 1)  // Stack full condition
        {
            printf("\nStack 1 full");
        }
        else
        {
            Dstack[++top1] = el;
        }
    }
    else if(stackNumber == 2) // For stack 2
    {
        if (top2 == top1 + 1) // Stack full condition
        {
            printf("\nStack 2 full");
        }
        else
        {
            Dstack[--top2] = el;
        }
    }
}

// Pop function to pop an element
int pop(int stackNumber)
{
    if (stackNumber == 1) // For stack 1
    {
        if (top1 == -1) // Stack empty condition
        {
            printf("\nStack 1 empty");
            return -1;
        }
        return Dstack[top1--];
    }
    else if(stackNumber == 2) // For stack 2
    {
        if (top2 == MAX) // Stack empty condition
        {
            printf("\nStack 2 empty");
            return -1;
        }
        return Dstack[top2++];
    }
}

// To display elements of stack
void display(int stackNumber)
{
    if (stackNumber == 1) // For stack 1
    {
        if (top1 == -1)
        {
            printf("\nStack 1 empty");
            return;
        }
        printf("\nElements of stack 1\n");
        for (int i = 0; i <= top1; i++)
            printf("%d ", Dstack[i]);
    }
    else if(stackNumber == 2) // For stack 2
    {
        if (top2 == MAX)
        {
            printf("\nStack 2 empty");
            return;
        }
        printf("\nElements of stack 2\n");
        for (int i = MAX - 1; i >= top2; i--)
            printf("%d ", Dstack[i]);
    }
}

int main()
{

    int sNum, ch, element, popped;
    printf("\nEnter stack number (1 or 2) ");
    scanf("%d", &sNum);
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
        printf("\n4.Change stack number");
        printf("\nPress anyother key to EXIT\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            push(sNum, element);
            break;
        case 2:
            popped = pop(sNum);
            printf("\nPopped element %d ", popped);
            break;
        case 3:
            display(sNum);
            break;
        case 4:
            printf("\nEnter stack number (1 or 2)");
            scanf("%d", &sNum);
            break;
        }
    } while (ch < 5);

    return 0;
}