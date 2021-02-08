// program to Search for an element in a given linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Time complexity: O(n), Space complexity: O(1)
int search(struct Node *head, int searchData)
{
    struct Node *curr = head;
    int pos = 1;
    while (curr && curr->data != searchData)
    {
        curr = curr->next;
        pos++;
    }
    if (curr)
        return pos;
    return -1;
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
    int searchData;
    printf("\nEnter data to search\n");
    scanf("%d", &searchData);
    int pos = search2(head, searchData);
    if (pos == -1)
        printf("\nNot found");
    else
        printf("\nFound at pos: %d", pos);

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