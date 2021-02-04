// Implementation of a stack using linked list

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Time complexity: O(1)
bool stack_empty()
{
    return top == NULL;
}

// Time complexity: O(1)
void stack_push(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (top)
        newNode->next = top;
    top = newNode;
}

// Time complexity: O(1)
int stack_pop()
{
    if (stack_empty())
        return -1;
    int del = top->data;
    struct Node *temp = top;
    top = top->next;
    free(temp);

    return del;
}

// Time complexity: O(1)
int stack_peek()
{
    if (stack_empty())
        return -1;
    return top->data;
}

void display()
{
    if (stack_empty())
        return;
    for (struct Node *ptr = top; ptr; ptr = ptr->next)
        printf("%d ", ptr->data);
}

int main()
{
    int ch;
    do
    {
        printf("\n\nEnter choice\n");
        printf("1.Push");
        printf("\n2.Pop");
        printf("\n3.Peek");
        printf("\n4.Display Stack\n");
        scanf("%d", &ch);
        int data, del, getTop;
        switch (ch)
        {
        case 1:

            printf("\nEnter data to insert\n");
            scanf("%d", &data);
            stack_push(data);
            break;
        case 2:
            del = stack_pop();
            if (del == -1)
                printf("\nStack Empty");
            else
                printf("\nPopped: %d", del);
            break;
        case 3:
            getTop = stack_peek();
            if (getTop == -1)
                printf("\nStack Empty");
            else
                printf("\nElement at top: %d", getTop);
            break;
        case 4:
            printf("\nStack: ");
            display();
        }
    } while (ch < 5);
    return 0;
}