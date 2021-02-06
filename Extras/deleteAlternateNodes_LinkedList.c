// Delete alternate nodes in a given linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Time complexity: O(n)
struct Node *deleteAlt(struct Node *head)
{
    struct Node *curr = head;
    while (curr && curr->next)
    {
        curr->next = curr->next->next;
        curr = curr->next;
    }

    return head;
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
    head = deleteAlt(head);

    printf("\nLinked List After deleting\n");
    display(head);

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
