// Given a linked list, delete the tail node

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Time complexity: O(n)
struct Node *deleteTail(struct Node *head)
{
    if (head == NULL || head->next == NULL) // if empty or single node
        return NULL;

    struct Node *curr = head;
    struct Node *prev = NULL;
    while (curr->next) // traverse till the last node
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    free(curr); // and delete it

    return head;
}

struct Node *insertAtHead(struct Node *, int);
void display(struct Node *);

int main()
{
    struct Node *head = NULL;
    head = insertAtHead(head, 15);
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 23);
    head = insertAtHead(head, 8);
    head = insertAtHead(head, 14);
    head = insertAtHead(head, 6);

    printf("\nLinked list\n");
    display(head);
    printf("\nLinked list after deleting tail\n");
    head = deleteTail(head);
    display(head);
    return 0;
}

struct Node *insertAtHead(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->next = head;
    return newNode;
}

void display(struct Node *head)
{
    if (head == NULL)
        return;
    printf("%d ", head->data);
    display(head->next);
}