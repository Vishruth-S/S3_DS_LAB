// Program to reverse elements of a Queue using a stack

#include <stdio.h>
#include <stdbool.h>

// === Queue and its funcions === //
int q[100];
int front = -1, rear = -1;
void qPush(int);
int qPop();
bool qEmpty();
void displayQ();
// === Stack and its functions === //
int stack[100];
int top = -1;
void stackPush(int);
int stackPop();
bool stackEmpty();

// Reverse a queue using a stack
void reverseElements()
{
    while (!qEmpty())
        stackPush(qPop());

    while (!stackEmpty())
        qPush(stackPop());
}

int main()
{
    qPush(12);
    qPush(5);
    qPush(23);
    qPush(34);
    qPush(8);
    qPush(10);
    printf("\nQueue\n");
    displayQ();

    reverseElements();

    printf("\nQueue after reverse\n");
    displayQ();
    return 0;
}

// === queue and stack functions === //
void qPush(int data)
{
    if (rear == 99)
        return;
    if (front == -1)
        ++front;
    q[++rear] = data;
}

int qPop()
{
    if (qEmpty())
        return -1;
    int del = q[front];
    if (rear == front)
        front = rear = -1;
    else
        front++;
    return del;
}

bool qEmpty()
{
    return front == -1 && rear == -1;
}

void stackPush(int data)
{
    if (top == 99)
        return;
    stack[++top] = data;
}

int stackPop()
{
    if (stackEmpty())
        return -1;
    return stack[top--];
}

bool stackEmpty()
{
    return top == -1;
}

void displayQ()
{
    for (int i = front; i <= rear; i++)
        printf("%d ", q[i]);
}