// program to find the predecessor of a given node in a singly linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Time complexity O(n), space complexity: O(1)
void findPredecessor(struct Node *head, int queryData)
{
    if (head == NULL)
    {
        printf("\nList empty");
        return;
    }

    if (head->data == queryData)
    {
        printf("\nEntered node is head node, no predecessor\n");
        return;
    }

    struct Node *curr = head, *prev = NULL;
    int position = -1;
    while (curr)
    {
        position++;
        if (curr->data == queryData)
        {
            printf("\nPredeccesor of %d is %d, found at position %d\n", queryData, prev->data, position);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("\nEntered node doesn't exist in list\n");
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
    int n;
    printf("\nEnter the data of the node whose predecessor is to be found\n");
    scanf("%d", &n);
    findPredecessor(head, n);

    return 0;
}

struct Node *insertAtHead(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
        return newNode;
    else
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
