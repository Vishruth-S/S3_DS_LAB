// Sort a linked list using Insertion Sort

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Time complexity: O(n^2), Space complexity: O(1)
struct Node *insertionSort(struct Node *head)
{
    if (head == NULL)
        return head;

    struct Node *dummyHead = (struct Node *)malloc(sizeof(struct Node));
    dummyHead->next = NULL;

    struct Node *curr = head;
    while (curr)
    {
        struct Node *prev = dummyHead;
        while (prev->next && prev->next->data < curr->data)
            prev = prev->next;

        struct Node *nextNode = curr->next;
        curr->next = prev->next;
        prev->next = curr;

        curr = nextNode;
    }

    return dummyHead->next;
}

struct Node *insertAtHead(struct Node *, int);
void display(struct Node *);

int main()
{
    struct Node *head = NULL;
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 60);
    head = insertAtHead(head, 6);
    head = insertAtHead(head, 8);
    head = insertAtHead(head, 12);
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 25);

    printf("\nLinked list\n");
    display(head);
    head = insertionSort(head);

    printf("\nSorted Linked List\n");
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
