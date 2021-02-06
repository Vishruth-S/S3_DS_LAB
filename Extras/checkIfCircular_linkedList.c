// Check if a given singly linked list is circular or not

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

// Time complexity: O(n)
bool isCircular(struct Node *head)
{
    if (head == NULL)
        return false;
    struct Node *head2 = head;
    do
    {
        head = head->next;
        if (head == head2)
            return true;
    } while (head);

    return false;
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

    if (isCircular(head))
        printf("\nCircular");
    else
        printf("\nNope");

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
