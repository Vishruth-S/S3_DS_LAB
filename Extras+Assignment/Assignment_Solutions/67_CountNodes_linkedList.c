// program to count number of nodes of a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Recursive
int count(struct Node *head)
{
    if (head == NULL)
        return 0;
    return 1 + count(head->next);
}

// Iterative
int count2(struct Node *head)
{
    int c = 0;
    while (head)
    {
        head = head->next;
        c++;
    }
    return c;
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
    int res = count(head);
    printf("\nNumber of nodes in List: %d", res);
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
