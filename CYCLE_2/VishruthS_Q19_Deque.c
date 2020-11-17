//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 2 QUESTION 19
//To implement a Deque using an array


#include <stdio.h>
#include <stdbool.h>

#define SIZE 20

int deq[SIZE];             // Double Ended Queue Array
int front = -1, rear = -1; // Initial values of front and rear

// To check if Queue is full
bool isFull()
{
    return (rear + 1) % SIZE == front;
}

// To check if Queue is empty
bool isEmpty()
{
    return front == -1 && rear == -1;
}

// Enqueue at Rear
void insertAtRear(int el)
{
    if (isFull())
        printf("\nQueue full");
    else
    {
        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE;
        deq[rear] = el;
    }
}

// Enqueue at Front
void insertAtfront(int el)
{
    if (isFull())
        printf("\nQueue full");
    else
    {
        if (isEmpty())
            front = rear = 0;
        else
            front = (front + SIZE - 1) % SIZE;
        deq[front] = el;
    }
}

// Dequeue at Front
void deleteAtFront()
{
    if (isEmpty())
        printf("\nQueue Empty");
    else
    {
        int deleted = deq[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
        printf("Deleted: %d", deleted);
    }
}

// Dequeue at Rear
void deleteAtRear()
{
    if (isEmpty())
        printf("\nQueue Empty");
    else
    {
        int deleted = deq[rear];
        if (front == rear)
            front = rear = -1;
        else
            rear = (rear + SIZE - 1) % SIZE;
        printf("Deleted: %d", deleted);
    }
}

// To print all elements in Queue
void Printdeq()
{
    if (isEmpty())
        printf("\nQueue empty");
    else
    {
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
                printf(" %d", deq[i]);
        }
        else
        {
            for (int i = front; i < SIZE; i++)
                printf(" %d", deq[i]);
            for (int i = 0; i <= rear; i++)
                printf(" %d", deq[i]);
        }
    }
}

//=== MAIN FUNCTION ===//
int main()
{
    int ch, element, del;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Enqueue at front");
        printf("\n2.Enqueue at rear");
        printf("\n3.Dequeue at front");
        printf("\n4.Dequeue at rear");
        printf("\n5.Display queue");
        printf("\n6.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            insertAtfront(element);
            break;
        case 2:
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            insertAtRear(element);
            break;
        case 3:
            deleteAtFront();
            break;
        case 4:
            deleteAtRear();
            break;
        case 5:
            Printdeq();
            break;
        }
    } while (ch < 6);
    
    return 0;
}