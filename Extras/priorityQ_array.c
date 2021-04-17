// Program to implement Priority Queue using array.
// Approach 1 - In this approach, Enqueue operation is modified while dequeue and peek are same as that of normal queue.

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
// Time complexity: O(n)
void enqueue(int current_value, int current_priority)
{
    if (rear == -1) // if queue is empty
        front = rear = 0;

    // find position to insert according to priority
    int pos = front;
    while (pos < rear && current_priority < pq[pos].priority)
        pos++;

    // shift all elements after position to the right
    for (int k = rear + 1; k > pos; k--)
        pq[k] = pq[k - 1];

    // and insert the current item at position
    pq[pos].value = current_value;
    pq[pos].priority = current_priority;

    rear++;
}

// dequeue
// Time complexity: O(1)
int dequeue()
{
    if (front == -1)
        return -1;

    int del = pq[front].value;
    if (front == rear - 1)
        front = rear = -1;
    else
        front++;
    return del;
}

// peek
// Time complexity: O(1)
int peek()
{
    if (front == -1)
        return -1;
    return pq[front].value;
}

void displayQ()
{
    if (front == -1)
    {
        printf("Queue empty\n");
        return;
    }
    printf("\nValue   |    Priority\n");
    for (int i = front; i < rear; i++)
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