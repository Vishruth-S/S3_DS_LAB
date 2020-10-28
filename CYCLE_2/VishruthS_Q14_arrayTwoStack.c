#include <stdio.h>

#define MAX 20

int Dstack[MAX];           // Single array for two stacks
int top1 = -1, top2 = MAX; // For 2 stacks

// Push function to insert element
void push(int s, int el)
{
    if (s == 1) // For stack 1
    {
        if (top1 == top2 - 1)
        {
            printf("\nStack 1 full");
        }
        else
        {
            Dstack[++top1] = el;
        }
    }
    else // For stack 2
    {
        if (top2 == top1 + 1)
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
int pop(int s)
{
    if (s == 1) // For stack 1
    {
        if (top1 == -1)
        {
            printf("\nStack 1 empty");
            return -1;
        }
        return Dstack[top1--];
    }
    else
    {
        if (top2 == MAX) // For stack 2
        {
            printf("\nStack 2 empty");
            return -1;
        }
        return Dstack[top2++];
    }
}

// To display elements of stack
void display(int s)
{
    if (s == 1) // For stack 1
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
    else // For stack 2
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

    int stackNumber, ch, element, popped;
    printf("\nEnter stack number (1 or 2) ");
    scanf("%d", &stackNumber);
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
            push(stackNumber, element);
            break;
        case 2:
            popped = pop(stackNumber);
            printf("\nPopped element %d ", popped);
            break;
        case 3:
            display(stackNumber);
            break;
        case 4:
            printf("\nEnter stack number (1 or 2)");
            scanf("%d", &stackNumber);
            break;
        }
    } while (ch < 5);

    return 0;
}