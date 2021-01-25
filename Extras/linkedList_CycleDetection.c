// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// (There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer)
// Refer: https://leetcode.com/problems/linked-list-cycle/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

bool detectCycle(struct Node *head)
{
    if (!head || !head->next)
        return false;
    struct Node *slow = head;
    struct Node *fast = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
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
    if (detectCycle(head))
        printf("\nThe linked list has a cycle");
    else
        printf("\nThe linked list has no cycle");
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
