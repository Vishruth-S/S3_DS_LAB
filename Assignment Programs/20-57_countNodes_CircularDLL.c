// Count number of nodes in a given Circular doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Time complexity: O(n), Space complexity: O(1)
int countNodes(struct Node *head)
{
    if (head == NULL)
        return 0;

    struct Node *curr = head;
    int count = 0;
    do
    {
        count++;
        curr = curr->next;
    } while (curr != head);

    return count;
}

struct Node *insertAtHead(struct Node *, int);
void display(struct Node *);

int main()
{
    struct Node *head = NULL;
    head = insertAtHead(head, 10);
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 30);
    head = insertAtHead(head, 40);
    head = insertAtHead(head, 50);
    printf("\nGiven circular DLL");
    display(head);
    int count = countNodes(head);
    printf("\n\nNumber of nodes: %d\n", count);
    return 0;
}

struct Node *last = NULL;
struct Node *insertAtHead(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode;
    newNode->next = newNode;
    if (last == NULL)
        last = newNode;
    else
    {
        head->prev = newNode;
        newNode->next = head;
        last->next = newNode;
        newNode->prev = last;
    }
    return newNode;
}

void display(struct Node *head)
{
    if (last == NULL)
    {
        printf("\nList empty");
        return;
    }
    struct Node *ptr = last->next;
    printf("\n");
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != last->next);
}
