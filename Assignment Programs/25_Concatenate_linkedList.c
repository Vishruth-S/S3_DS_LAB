// program to Concatenate two linked lists

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Time complexity: O(m), where m is the number of elements in first linked list
struct Node *concatenate(struct Node *head1, struct Node *head2)
{
    if (head1 == NULL)
        return head2;

    struct Node *curr = head1;
    while (curr->next)
        curr = curr->next;
    curr->next = head2;
    return head1;
}

struct Node *insertAtHead(struct Node *, int);
void display(struct Node *);

int main()
{
    struct Node *head1 = NULL, *head2 = NULL;
    head1 = insertAtHead(head1, 40);
    head1 = insertAtHead(head1, 30);
    head1 = insertAtHead(head1, 20);
    head1 = insertAtHead(head1, 10);

    printf("\nLinked list 1\n");
    display(head1);
    head2 = insertAtHead(head2, 70);
    head2 = insertAtHead(head2, 60);
    head2 = insertAtHead(head2, 50);

    printf("\nLinked list 2\n");
    display(head2);

    head1 = concatenate(head1, head2);
    printf("\nLinked list 1 after concatenating with 2\n");
    display(head1);
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
