// Program to implement Priority Queue using Linked list.
// Approach 2 - In this approach,  dequeue and peek are modified while Enqueue is same as that of normal queue.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    int priority;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *last = NULL;

// enqueue
// Time complexity: O(1)
void enqueue(int current_val, int current_priority)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = current_val;
    newNode->priority = current_priority;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else
        last->next = newNode;

    last = newNode;
}

// dequeue
// Time complexity: O(n)
int dequeue()
{
    if (head == NULL)
        return -1;

    // find node with highest priority and delete it from linked list
    struct Node *pos, *prev_pos = NULL;
    int highest_priority = -1;
    for (struct Node *ptr = head, *prev = NULL; ptr; prev = ptr, ptr = ptr->next)
    {
        if (ptr->priority > highest_priority)
        {
            prev_pos = prev;
            pos = ptr;
            highest_priority = ptr->priority;
        }
    }
    if (prev_pos == NULL)
        head = pos->next;
    else
        prev_pos->next = pos->next;

    if (last == pos)
        last = prev_pos;

    int del = pos->data;
    free(pos);
    return del;
}

// peek
// Time complexity: O(n)
int peek()
{
    if (head == NULL)
        return -1;

    struct Node *pos;
    int highest_priority = -1;
    for (struct Node *ptr = head; ptr; ptr = ptr->next)
    {
        if (ptr->priority > highest_priority)
        {
            pos = ptr;
            highest_priority = ptr->priority;
        }
    }

    return pos->data;
}

void displayQ()
{
    if (head == NULL)
    {
        printf("\nQueue Empty\n");
        return;
    }
    printf("\nValue   |    Priority\n");
    for (struct Node *ptr = head; ptr; ptr = ptr->next)
        printf("   %d         %d   \n", ptr->data, ptr->priority);
}

int main()
{
    int ch, val, priority, del, p;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Peek");
        printf("\n4.Display");
        printf("\n5.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter value to insert\n");
            scanf("%d", &val);
            printf("\nEnter priority\n");
            scanf("%d", &priority);
            enqueue(val, priority);
            break;
        case 2:
            del = dequeue();
            if (del == -1)
                printf("\nQueue empty");
            else
                printf("\nRemoved from queue: %d", del);
            break;
        case 3:
            p = peek();
            if (p == -1)
                printf("\nQueue empty");
            else
                printf("\nValue with highest priority: %d", p);
            break;
        case 4:
            displayQ();
        }
    } while (ch < 5);

    return 0;
}