// Check whether the length of linked list is even or odd.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

// Method 1 - simple iterative - count the number of nodes
// Time complexity: O(n)
int isLengthEvenOrOdd(struct Node *head)
{
    int c = 0;
    while (head)
    {
        head = head->next;
        c++;
    }
    return c % 2;
}

// Method 2 - Recursion + bit manipulation
// Time complexity: O(n)
int isLengthEvenOrOdd2(struct Node *head)
{
    if (head == NULL)
        return 0;
    return 1 ^ isLengthEvenOrOdd2(head->next);
}

struct Node *insertAtHead(struct Node *, int);
void display(struct Node *);

int main()
{
    struct Node *head = NULL;
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 60);
    head = insertAtHead(head, 40);
    head = insertAtHead(head, 50);
    head = insertAtHead(head, 30);
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 25);

    printf("\nLinked list\n");
    display(head);

    if (isLengthEvenOrOdd2(head))
        printf("\nOdd");
    else
        printf("\nEven");

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
