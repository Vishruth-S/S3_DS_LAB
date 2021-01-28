// program to find the successor of a given node in a singly linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Time complexity O(n), space complexity: O(1)
void findSuccessor(struct Node *head, int queryData)
{
    if (head == NULL)
    {
        printf("\nList empty");
        return;
    }

    struct Node *curr = head;
    while (curr && curr->data != queryData)
        curr = curr->next;
    if (!curr)
        printf("\nEntered node doesn't exist in list\n");
    else if (!curr->next)
        printf("\nEntered node is tail, no successor found\n");
    else
        printf("\nSuccessor %d", curr->next->data);
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
    printf("\nEnter the data of the node whose succesor is to be found\n");
    scanf("%d", &n);
    findSuccessor(head, n);

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
