// program to print the maximum and minimum element in a linked list

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define max(x, y) ((x > y) ? x : y)
#define min(x, y) ((x < y) ? x : y)

struct Node
{
    int data;
    struct Node *next;
};

// Time complexity: O(n)
void printMinMax(struct Node *root)
{
    int maxi = INT_MIN, mini = INT_MAX;
    struct Node *curr = root;
    while (curr)
    {
        maxi = max(maxi, curr->data);
        mini = min(mini, curr->data);
        curr = curr->next;
    }
    printf("\nMaximum value: %d", maxi);
    printf("\nMinimum value: %d\n", mini);
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
    printMinMax(head);

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
    if (head)
    {
        printf("%d ", head->data);
        display(head->next);
    }
}
