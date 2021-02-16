// Given a linked list of numbers, check if it forms a palindrome

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

// Method 1 - Using extra linked list.
// Logic - Create a reversed copy of given linked list and compare them
// Time complexity: O(n), Space complexity: O(n)
// Code not shown.

// Method 2 - No extra linked list - By reversing only second half in-place
// Logic - Reverse only the second half of the given linked list
// And compare first half with reversed second half
// Time complexity: O(n), Space complexity: O(1)
bool isPalindrome(struct Node *head)
{
    if (!head || !head->next)
        return true;

    // Get to the middle
    struct Node *middle = head, *fast = head->next;
    while (fast && fast->next)
    {
        middle = middle->next;
        fast = fast->next->next;
    }

    // Reverse second half
    struct Node *curr = middle->next, *prev = NULL, *next;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    middle->next = prev;

    // Check if first half is equal to reversed second half
    struct Node *first = head, *second = middle->next;
    while (first && second)
    {
        if (first->data != second->data)
            return false;

        first = first->next;
        second = second->next;
    }

    return true;
}

struct Node *insertAtHead(struct Node *, int);
void display(struct Node *);

int main()
{
    struct Node *head = NULL;
    head = insertAtHead(head, 1);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 1);

    printf("\nLinked list\n");
    display(head);

    if (isPalindrome(head))
        printf("\nPalindrome");
    else
        printf("\nNope");

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
