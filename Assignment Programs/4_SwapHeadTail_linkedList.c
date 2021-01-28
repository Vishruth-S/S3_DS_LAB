// program to swap first and last nodes of a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Time complexity: O(n)
struct Node *swapHeadTail(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *tail = head;
    struct Node *prev = NULL;
    while (tail->next)
    {
        prev = tail;
        tail = tail->next;
    }
    prev->next = head;
    tail->next = head->next;
    head->next = NULL;
    head = tail;
    return head;
}

struct Node *insertAtHead(struct Node *, int);
void display(struct Node *);

int main()
{
    struct Node *head = NULL;
    head = insertAtHead(head, 60);
    head = insertAtHead(head, 50);
    head = insertAtHead(head, 40);
    head = insertAtHead(head, 30);
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 10);
    printf("\nLinked list Before Swap\n");
    display(head);
    head = swapHeadTail(head);
    printf("\nLinked list After Swap\n");
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
