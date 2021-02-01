// program to insert a node at a given position in a doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

struct Node *insertAtPosition(struct Node *head, int pos, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node *curr = head;
    if (pos == 1) // in case of inserting at head
    {
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = NULL;
        return newNode;
    }

    while (curr && --pos > 1)
        curr = curr->next;
    if (!curr)
    {
        printf("\nPosition exceeded list size\n");
        return head;
    }

    newNode->next = curr->next;
    newNode->prev = curr;
    if (curr->next)
        curr->next->prev = newNode;
    curr->next = newNode;

    return head;
}
struct Node *insertAtHead(struct Node *, int);
void display(struct Node *);

int main()
{
    struct Node *head = NULL;
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 1);
    printf("\nDoubly linked list:\n");
    display(head);

    int pos, data;
    printf("\nEnter position to insert data\n");
    scanf("%d", &pos);
    printf("Enter data to be inserted\n");
    scanf("%d", &data);

    head = insertAtPosition(head, pos, data);
    printf("\nLinked list after insertion\n");
    display(head);

    return 0;
}

struct Node *insertAtHead(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (head)
    {
        head->prev = newNode;
        newNode->next = head;
    }
    return newNode;
}

void display(struct Node *head)
{
    if (!head)
    {
        printf("list empty");
        return;
    }
    struct Node *curr = head;
    while (curr)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}
