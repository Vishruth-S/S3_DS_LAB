#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

bool qEmpty()
{
    return front == NULL && rear == NULL;
}

// Time Complexity: O(1)
void enQueue(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (rear == NULL)
        front = newNode;
    else
        rear->next = newNode;
    rear = newNode;
}

// Time Complexity: O(1)
int deQueue()
{
    if (qEmpty())
        return -1;

    int deleted = front->data;
    struct Node *temp = front;
    if (front == rear)
        front = rear = NULL;
    else
        front = front->next;

    free(temp);
    return deleted;
}

// Time Complexity: O(1)
int peek()
{
    if (qEmpty())
        return -1;
    return front->data;
}

void display()
{
    if (qEmpty())
    {
        printf("Empty\n");
        return;
    }
    for (struct Node *curr = front; curr; curr = curr->next)
        printf("%d ", curr->data);
}

int main()
{
    int ch;
    do
    {
        printf("\n\nEnter choice\n");
        printf("1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Peek");
        printf("\n4.Display Queue\n");
        scanf("%d", &ch);
        int data, del, getFront;
        switch (ch)
        {
        case 1:

            printf("\nEnter data to insert\n");
            scanf("%d", &data);
            enQueue(data);
            break;
        case 2:
            del = deQueue();
            if (del == -1)
                printf("\nQueue Empty");
            else
                printf("\nDeleted: %d", del);
            break;
        case 3:
            getFront = peek();
            if (getFront == -1)
                printf("\nQueue Empty");
            else
                printf("\nElement at front: %d", getFront);
            break;
        case 4:
            printf("\nQueue: ");
            display();
        }
    } while (ch < 5);

    return 0;
}