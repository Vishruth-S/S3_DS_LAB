// Given a linked list, interchange the first half with second half

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Time complexity: O(n), Space complexity: O(1)
struct Node *swapFirstAndSecondHalf(struct Node *head)
{
    if (head == NULL || head->next == NULL) // base cases
        return head;

    struct Node *middle = head, *end = head, *prev = NULL, *last = head;
    while (end && end->next) // find middle node and last node
    {
        prev = middle;
        middle = middle->next;
        if (end->next->next == NULL)
            last = end->next;
        else
            last = end->next->next;
        end = end->next->next;
    }

    prev->next = NULL;
    last->next = head;
    head = middle;

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
    printf("\nLinked list\n");
    display(head);
    head = swapFirstAndSecondHalf(head);
    printf("\nLinked list after swapping first and last halves\n");
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