// program to remove all occurences of a value from a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Iterative Solution
// Time complexity: O(n), Space complexity: O(1)
struct Node *removeOccurences(struct Node *head, int data)
{
    struct Node *curr = head, *prev = NULL, *temp = NULL;

    // In case node to be deleted is head node
    while (head && head->data == data)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    // Otherwise, traverse the list
    for (curr = head; curr; curr = curr->next)
    {
        // and if required node is found, delete it
        while (curr && curr->data == data)
        {
            temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            free(temp);
        }
        if (curr == NULL)
            break;
        prev = curr;
    }

    return head;
}

// Recursive Solution
// Time complexity: O(n), Space complexity: O(n)
struct Node *removeOccurences2(struct Node *head, int data)
{
    if (head == NULL)
        return head;
    head->next = removeOccurences2(head->next, data);
    return head->data == data ? head->next : head;
}

struct Node *insertAtHead(struct Node *, int);
void display(struct Node *);

int main()
{
    struct Node *head = NULL;
    head = insertAtHead(head, 60);
    head = insertAtHead(head, 50);
    head = insertAtHead(head, 50);
    head = insertAtHead(head, 30);
    head = insertAtHead(head, 50);
    head = insertAtHead(head, 40);
    head = insertAtHead(head, 30);
    head = insertAtHead(head, 30);
    head = insertAtHead(head, 30);
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 10);
    head = insertAtHead(head, 10);
    head = insertAtHead(head, 30);
    head = insertAtHead(head, 10);
    head = insertAtHead(head, 10);
    head = insertAtHead(head, 10);
    printf("\nLinked list\n");
    display(head);
    int n;
    printf("\nEnter the data of the node to be removed\n");
    scanf("%d", &n);
    head = removeOccurences(head, n);
    printf("\nLinked list after removing all occurences of %d\n", n);
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