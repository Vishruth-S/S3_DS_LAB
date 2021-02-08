// program to Search for an element in a given linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Recursive
// Time complexity: O(n), Space complexity: O(n)
int countNodes(struct Node *head)
{
    if (head == NULL)
        return 0;
    return 1 + countNodes(head->next);
}

// Iterative
// Time complexity: O(n), Space complexity: O(1)
int countNodes2(struct Node *head)
{
    int count = 0;
    struct Node *curr = head;
    while (curr)
    {
        count++;
        curr = curr->next;
    }
    return count;
}
struct Node *insertAtHead(struct Node *, int);
void display(struct Node *);

int main()
{
    struct Node *head = NULL;
    head = insertAtHead(head, 35);
    head = insertAtHead(head, 6);
    head = insertAtHead(head, 28);
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 42);
    head = insertAtHead(head, 12);
    printf("\nLinked list\n");
    display(head);
    int n = countNodes(head);
    printf("\nNumber of nodes: %d", n);

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