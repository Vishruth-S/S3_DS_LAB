// program to remove duplicates from a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Method 1 - Brute force - Time complexity: O(n*n), space complexity: O(1)
struct Node *removeDuplicates(struct Node *head)
{
    struct Node *curr, *temp, *prev = NULL;
    for (temp = head; temp; temp = temp->next)
    {
        prev = temp;
        for (curr = temp->next; curr; curr = curr->next)
        {
            while (curr && temp->data == curr->data)
            {
                prev->next = curr->next;
                curr = curr->next;
            }
            if (curr == NULL)
                break;
            prev = curr;
        }
    }
    return head;
}

// Method 2 - Optimized using hashing- Time complexity: O(n), space complexity: O(n)
struct Node *removeDuplicates2(struct Node *head)
{
    int counts[1000] = {0};
    struct Node *curr, *prev = NULL;
    for (curr = head; curr; curr = curr->next)
    {
        if (counts[curr->data] >= 1)
        {
            prev->next = curr->next;
            continue;
        }
        prev = curr;
        counts[curr->data]++;
    }
    return head;
}

struct Node *insertAtHead(struct Node *, int);
void display(struct Node *);

int main()
{
    struct Node *head = NULL;
    head = insertAtHead(head, 60);
    head = insertAtHead(head, 50);
    head = insertAtHead(head, 30);
    head = insertAtHead(head, 50);
    head = insertAtHead(head, 40);
    head = insertAtHead(head, 30);
    head = insertAtHead(head, 10);
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 10);
    head = insertAtHead(head, 30);
    head = insertAtHead(head, 30);
    head = insertAtHead(head, 30);
    printf("\nLinked list\n");
    display(head);
    head = removeDuplicates(head);
    printf("\nLinked list after removing all duplicates (method 1)\n");
    display(head);
    head = removeDuplicates2(head);
    printf("\nLinked list after removing all duplicates (method 2)\n");
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