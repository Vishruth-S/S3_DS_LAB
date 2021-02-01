// program to delete the first node (head) of a singly linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Time complexity: O(1)
struct Node *deleteHead(struct Node *head)
{
    if (head == NULL)
        return head;

    struct Node *temp = head;
    head = head->next;
    free(temp);
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
    printf("\nLinked list\n");
    display(head);

    head = deleteHead(head);
    printf("\nLinked list after deleting first node\n");
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
    if (!head)
        return;
    printf("%d ", head->data);
    display(head->next);
}
