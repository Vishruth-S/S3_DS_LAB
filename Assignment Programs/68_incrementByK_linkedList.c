// program to add a value K to all nodes data of a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Method 1 - Recursive - Time complexity: O(n), Space complexity: O(n)
void incrementByK(struct Node *head, int k)
{
    if (head == NULL)
        return;
    head->data += k;
    incrementByK(head->next, k);
}

// Method 2 - Iterative - Time complexity: O(n), Space complexity: O(1)
void incrementByK_iterative(struct Node *head, int k)
{
    struct Node *curr = head;
    while (curr)
    {
        curr->data += k;
        curr = curr->next;
    }
}

struct Node *insertAtHead(struct Node *, int);
void display(struct Node *);

int main()
{
    struct Node *head = NULL;
    head = insertAtHead(head, 70);
    head = insertAtHead(head, 60);
    head = insertAtHead(head, 50);
    head = insertAtHead(head, 40);
    head = insertAtHead(head, 30);
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 10);
    printf("\nLinked list\n");
    display(head);
    int k;
    printf("\nEnter value K\n");
    scanf("%d", &k);
    incrementByK(head, k);
    printf("\nLinekd list after incrementing data by %d\n", k);
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
