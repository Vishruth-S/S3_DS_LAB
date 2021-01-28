// program to insert elements into sorted linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Time complexity: O(n)
struct Node *insertInSortedList(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) // if linked list is empty
        return newNode;

    if (data < head->data) // if data to be inserted at head
    {
        newNode->next = head;
        return newNode;
    }

    struct Node *curr = head, *prev = NULL;
    while (curr && data > curr->data)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = newNode;
    newNode->next = curr;

    return head;
}
void display(struct Node *);

int main()
{
    struct Node *head = NULL;

    head = insertInSortedList(head, 10);
    head = insertInSortedList(head, 30);
    head = insertInSortedList(head, 40);
    head = insertInSortedList(head, 50);
    head = insertInSortedList(head, 20);
    head = insertInSortedList(head, 5);
    head = insertInSortedList(head, 15);
    head = insertInSortedList(head, 60);
    head = insertInSortedList(head, 15);
    printf("\nLinked list\n");
    display(head);
    return 0;
}

void display(struct Node *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}