//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 2 QUESTION 13
//To implement a Queue using an array

#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int q[MAX]; // Array Queue
int front = -1, rear = -1; // Initial value of front and rear

// To check if Queue is full
bool qIsFull()
{
    return rear == MAX - 1;
}

// To check if Queue is empty
bool qIsEmpty()
{
    return front == -1 && rear == -1;
}

// To insert element into Queue
void enqueue(int el)
{
    if (qIsFull())
        printf("\nQueue full");
    else
    {
        if (qIsEmpty())       // if the element to be inserted is first element
            front = rear = 0; // Then front and rear must be set to 0;
        else
        {
            rear++; // otherwise, only rear needs to be incremented
        }
        q[rear] = el;
    }
}

// To pop element from Queue
void dequeue()
{
    int deleted;
    if (qIsEmpty())
    {
        printf("\nQueue empty");
    }
    else
    {
        deleted = q[front];
        
        if (front == rear) // Check if element to be removed is last element in queue
            front = rear = -1; // Then queue must be reset.
        else
            front++; // else only front needs to be incremented
        
        printf("\nDeleted from queue: %d", deleted);
    }
}

// To print the elements of Queue
void printQ()
{
    if (qIsEmpty())
        printf("\nQueue empty");
    else
    {
        printf("\nElements of Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", q[i]);
    }
}

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
