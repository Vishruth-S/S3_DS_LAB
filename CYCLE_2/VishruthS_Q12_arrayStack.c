#include <stdio.h>

#define MAX 100

int stack[100], top = -1; // stack array and top

// Push function to insert element
void push(int data)
{
    if (top == MAX - 1)
        printf("\nStack overflow");
    else
        stack[++top] = data;
}

// Pop function to pop element
int pop()
{
    if (top == -1)
        printf("\nStack empty");
    else
        return stack[top--];
}

// To print elements of stack
void display()
{
    printf("\n");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
}

int main()
{
    int ch, element, del;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display stack");
        printf("\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            push(element);
            break;
        case 2:
            del = pop();
            printf("\nDeleted: %d", del);
            break;
        case 3:
            display();
            break;
        }
    } while (ch < 4);

    return 0;
}