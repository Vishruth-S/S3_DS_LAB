// Program to implement Priority Queue using array.
// Approach 2- In this approach,  dequeue and peek are modified while Enqueue is same as that of normal queue.

#include <stdio.h>
#include <stdlib.h>

struct item
{
    int value;
    int priority;
};

struct item pq[100]; // array of items - priority queue
int rear = -1;
int front = -1;

// enqueue
// Time complexity: O(1)
void enqueue(int current_val, int current_priority)
{
    if (front == -1)
        front = rear = 0;
    else
        rear++;
    pq[rear].value = current_val;
    pq[rear].priority = current_priority;
}

// dequeue
// Time complexity: O(n)
int dequeue()
{
    if (front == -1)
        return -1;

    int highest_priority = -1;
    int index = -1;
    // Find value with highest priority
    for (int i = front; i <= rear; i++)
    {
        if (pq[i].priority > highest_priority)
        {
            highest_priority = pq[i].priority;
            index = i;
        }
    }

    int deleted = pq[index].value;

    // right-shift all elements to the left of this value
    for (int k = index; k > front; k--)
        pq[k] = pq[k - 1];

    if (front == rear)
        front = rear = -1;
    else
        front++;

    return deleted;
}

// peek
// Time complexity: O(n)
int peek()
{
    if (front == -1)
        return -1;

    int highest_priority = -1;
    int index = -1;
    for (int i = front; i <= rear; i++)
    {
        if (pq[i].priority > highest_priority)
        {
            highest_priority = pq[i].priority;
            index = i;
        }
    }
    return pq[index].value;
}

void displayQ()
{
    if (front == -1)
    {
        printf("Queue empty\n");
        return;
    }
    printf("\nValue   |    Priority\n");
    for (int i = front; i <= rear; i++)
        printf("   %d         %d   \n", pq[i].value, pq[i].priority);
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