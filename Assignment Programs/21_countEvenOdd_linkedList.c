// program to count number of even and odd nodes of a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Method 1 - Simple Iterative
// Time complexity O(n), space complexity: O(1)
void countEvenOdd(struct Node *head)
{
    int evenCount = 0, oddCount = 0;
    while (head)
    {
        if (head->data % 2)
            oddCount++;
        else
            evenCount++;
        head = head->next;
    }
    printf("\nCount of odd numbers: %d", oddCount);
    printf("\nCount of even numbers: %d", evenCount);
}

// Method 2- Using Recursion
// Time complexity O(n), space complexity: O(n)
int countEven(struct Node *head)
{
    if (head == NULL)
        return 0;
    if (head->data % 2 == 0)
        return 1 + countEven(head->next);
    return countEven(head->next);
}
int countOdd(struct Node *head)
{
    if (head == NULL)
        return 0;
    if (head->data % 2 == 0)
        return 1 + countOdd(head->next);
    return countOdd(head->next);
}

struct Node *insertAtHead(struct Node *, int);
void display(struct Node *);

int main()
{
    struct Node *head = NULL;
    head = insertAtHead(head, 9);
    head = insertAtHead(head, 8);
    head = insertAtHead(head, 7);
    head = insertAtHead(head, 6);
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 1);
    printf("\nLinked list\n");
    display(head);
    countEvenOdd(head);
    // ---for Recursive
    // int evenCount = countEven(head);
    // int OddCount = countOdd(head);
    // printf("\nEven %d", evenCount);
    // printf("\nOdd %d", OddCount);
    return 0;
}

struct Node *insertAtHead(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head)
        newNode->next = head;
    return newNode;
}

void display(struct Node *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
