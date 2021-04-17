// Priority Queue using a linked list where priority of an element is its value
// Approach 1 - In this approach, Enqueue operation is modified while dequeue and peek are same as that of normal queue.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    int priority;
    struct Node *next;
};

struct Node *front = NULL;

// enqueue
// Time complexity: O(n)
void enqueue(int current_val, int current_priority)
{
    // traverse the list until correct position reached and insert the new node there
    struct Node *pos = front, *prev = NULL;

    while (pos && current_priority < pos->priority)
    {
        prev = pos;
        pos = pos->next;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = current_val;
    newNode->priority = current_priority;

    newNode->next = pos;
    if (prev == NULL)
        front = newNode;
    else
        prev->next = newNode;
}

// dequeue
// Time complexity: O(1)
int dequeue()
{
    if (front == NULL)
        return -1;

    struct Node *del_node = front;
    int del_value = front->data;

    front = front->next;
    free(del_node);

    return del_value;
}

// peek
// Time complexity: O(1)
int peek()
{
    if (front == NULL)
        return -1;

    return front->data;
}

void displayQ()
{
    if (front == NULL)
    {
        printf("\nQueue Empty\n");
        return;
    }
    printf("\nValue   |    Priority\n");
    for (struct Node *ptr = front; ptr; ptr = ptr->next)
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