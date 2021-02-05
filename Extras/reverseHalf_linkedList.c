// Given a linked list, reverse only the second half of elements
// Note that this must be done in-place by modifying pointers, and no extra list may be created
// Example: 1-2-3-4-5-6-7-8 should become 1-2-3-4-8-7-6-5

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Time complexity: O(n), Space complexity: O(1)
struct Node *reverseSecondHalf(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *mid = head, *fast = head->next;
    while (fast && fast->next) // get to the middle of the linked list
    {
        mid = mid->next;
        fast = fast->next->next;
    }
    // Reverse from the middle node
    struct Node *curr = mid->next;
    struct Node *prev = NULL, *next = curr->next;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    mid->next = prev; // make sure the end of the first half now points to the updated second half

    return head;
}

struct Node *insertAtHead(struct Node *, int);
void display(struct Node *);

int main()
{
    struct Node *head = NULL;
    head = insertAtHead(head, 8);
    head = insertAtHead(head, 7);
    head = insertAtHead(head, 6);
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 1);
    printf("\nLinked list\n");
    display(head);
    head = reverseSecondHalf(head);
    printf("\nLinked list After Reversing second half\n");
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
