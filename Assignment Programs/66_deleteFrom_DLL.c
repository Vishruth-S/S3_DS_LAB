// program to insert a node at a given position in a doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

struct Node *deleteNode(struct Node *head, int data)
{
    struct Node *curr = head;
    while (curr && curr->data != data)
        curr = curr->next;
    if (!curr)
    {
        printf("\nEntered element doesn't exist in list\n");
        return head;
    }

    if (curr == head) // if head node to be deleted
    {
        head = head->next;
        head->prev = NULL;
        free(curr);
        return head;
    }

    curr->prev->next = curr->next;
    if (curr->next)
        curr->next->prev = curr->prev;
    free(curr);

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

    int data;
    printf("\nEnter data to be deleted\n");
    scanf("%d", &data);

    head = deleteNode(head, data);
    printf("\nLinked list after deleting %d\n", data);
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
