// program which swaps the Kth and K+1 th elements in a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *swapNodes(struct Node *head, int k)
{
    struct Node *curr = head, *prev = NULL, *nextNode = NULL;
    while (curr && --k)
    {
        prev = curr;
        curr = curr->next;
    }
    nextNode = curr->next;
    if (!nextNode)
    {
        printf("\nValue of K exceeded max size\n");
        return head;
    }

    if (prev)
        prev->next = nextNode;
    else
        head = nextNode;
    curr->next = nextNode->next;
    nextNode->next = curr;

    return head;
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
    int k;
    printf("\nEnter k\n");
    scanf("%d", &k);
    head = swapNodes(head, k);
    printf("\nLinked list after swapping node %d and %d\n", k, k + 1);
    display(head);
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
    if (head == NULL)
        return;
    printf("%d ", head->data);
    display(head->next);
}