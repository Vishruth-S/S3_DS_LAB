// program to spilt a linked list into two lists, in such a manner that the
// first linked list contains the odd numbered nodes
// and second linked list contains the even numbered nodes.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *evenList = NULL, *oddList = NULL;
void splitOddEven(struct Node *head)
{
    struct Node *curr1 = evenList, *curr2 = oddList;
    int pos = 1;
    for (struct Node *curr = head; curr; curr = curr->next, pos++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = curr->data;
        newNode->next = NULL;
        if (pos % 2 == 0) // even position nodes
        {
            if (evenList == NULL)
                evenList = newNode;
            else
                curr1->next = newNode;
            curr1 = newNode;
        }
        else // odd position nodes
        {
            if (oddList == NULL)
                oddList = newNode;
            else
                curr2->next = newNode;
            curr2 = newNode;
        }
    }
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
    splitOddEven(head);
    printf("\nLinked list 1 containing odd numbered nodes\n");
    display(oddList);
    printf("\nLinked list 2 containing even numbered nodes\n");
    display(evenList);

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
