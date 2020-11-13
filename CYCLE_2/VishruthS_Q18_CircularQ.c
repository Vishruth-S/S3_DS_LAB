//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 2 QUESTION 18
//To implement a Circular Queue using an array

#include <stdio.h>
#include <stdbool.h>

#define SIZE 20 // maximum size

int cq[SIZE];              // Array for circular queue
int front = -1, rear = -1; // Initializing front and rear

// Check if queue is empty
bool isEmpty()
{
    return front == -1 && rear == -1;
}

// Check if queue is full
bool isFull()
{
    return (rear + 1) % SIZE == front;
}

// To insert element
void enqueue(int el)
{
    if (isFull())
        printf("\nQueue Full");
    else
    {
        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE;
        cq[rear] = el;
    }
}

// To remove element
void dequeue()
{
    if (isEmpty())
        printf("\nQueue Empty");
    else
    {
        int deleted = cq[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
        printf("Deleted: %d", deleted);
    }
}

// To display the queue
void printQ()
{
    if (isEmpty())
        printf("\nQueue empty");
    else
    {
        if (front <= rear)
            for (int i = front; i <= rear; i++)
                printf("%d ", cq[i]);
        else
        {
            for (int i = front; i < SIZE; i++)
                printf("%d ", cq[i]);
            for (int i = 0; i <= rear; i++)
                printf("%d ", cq[i]);
        }
    }
}


// ==== MAIN FUNCTION === //
int main()
{
    int ch, element;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display queue");
        printf("\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printQ();
            break;
        }
    } while (ch < 4);

    return 0;
}