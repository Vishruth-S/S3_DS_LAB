// Sort a linked list using Bubble Sort

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void swap(struct Node *a, struct Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

struct Node *bubbleSort(struct Node *head)
{
    int swapped = 0;
    struct Node *curr = head, *prev = NULL, *curr2 = NULL;
    do
    {
        swapped = 0;
        for (curr = head; curr->next != curr2; curr = curr->next)
        {
            swapped = 0;
            if (curr->data > curr->next->data)
            {
                swapped = 1;
                swap(curr, curr->next);
            }
        }
        curr2 = curr;
    } while (swapped);

    return head;
}

struct Node *insertAtHead(struct Node *, int);
void display(struct Node *);

int main()
{
    struct Node *head = NULL;
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 60);
    head = insertAtHead(head, 40);
    head = insertAtHead(head, 50);
    head = insertAtHead(head, 30);
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 25);

    printf("\nLinked list\n");
    display(head);
    head = bubbleSort(head);

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
