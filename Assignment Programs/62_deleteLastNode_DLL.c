// program to delete the last node from a doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

// Time complexity: O(n)
struct Node *deleteLastNode(struct Node *head)
{
    if (head == NULL)
        return head;
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    struct Node *curr = head, *last = NULL;
    while (curr->next->next)
        curr = curr->next;
    last = curr->next;
    curr->next = NULL;
    free(last);

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

    head = deleteLastNode(head);
    printf("\nLinked list after removing last node\n");
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
