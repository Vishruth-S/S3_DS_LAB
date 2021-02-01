// Given a doubly linked list , removes a node with a particular value from the list
// and insert it in the front

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

// Time complexity: O(n)
struct Node *deleteAndPrepend(struct Node *head, int query)
{
    struct Node *curr = head;
    while (curr && curr->data != query)
        curr = curr->next;
    if (curr == NULL)
    {
        printf("\nNode with given data does not exist");
        return head;
    }
    if (curr == head)
        return head;

    curr->prev->next = curr->next;
    if (curr->next)
        curr->next->prev = curr->prev;

    curr->prev = NULL;
    curr->next = head;
    head->prev = curr;
    head = curr;

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
    int query;
    printf("\nEnter element to remove and add to head\n");
    scanf("%d", &query);

    head = deleteAndPrepend(head, query);
    printf("\nLinked list after removing and adding to head\n");
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
        return;
    printf("%d ", head->data);
    display(head->next);
}