// Given two linear lists L1 and L2. Find L1 union L2 (means all
// elements in L1 and L2) into a new list called L3.
// Then make L3 as a sorted list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *list3 = NULL;
int visited[1000] = {0};
struct Node *insertNode(struct Node *, int);

// Time complexity: O(m + n), Space complexity: O(m + n)
void findUnion(struct Node *list1, struct Node *list2)
{
    struct Node *curr = NULL, *curr1, *curr2;
    for (curr1 = list1; curr1; curr1 = curr1->next)
    {
        visited[curr1->data] = 1; // Keep track of values so as to avoid duplicates
        curr = insertNode(curr, curr1->data);
    }

    for (curr2 = list2; curr2; curr2 = curr2->next)
        if (!visited[curr2->data]) // only taking previously unseen values
            curr = insertNode(curr, curr2->data);
}
// Time complexity: O(1)
struct Node *insertNode(struct Node *curr, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list3 == NULL)
        list3 = newNode;
    else
        curr->next = newNode;
    curr = newNode;
}

// Sorting algorithm used: Selection sort. Any other algorithm may also be used
// Time complexity: O(n^2)
void sortLinkedList(struct Node *list3)
{
    if (list3 == NULL)
        return;
    struct Node *curr, *curr2, *min = NULL;
    for (curr2 = list3; curr2; curr2 = curr2->next)
    {
        min = curr2;
        for (curr = curr2; curr; curr = curr->next)
            if (curr->data < min->data)
                min = curr;

        int temp = curr2->data;
        curr2->data = min->data;
        min->data = temp;
    }
}

struct Node *insertAtHead(struct Node *, int);
void display(struct Node *);

int main()
{
    struct Node *head1 = NULL, *head2 = NULL;
    head1 = insertAtHead(head1, 40);
    head1 = insertAtHead(head1, 30);
    head1 = insertAtHead(head1, 20);
    head1 = insertAtHead(head1, 60);
    head1 = insertAtHead(head1, 10);

    printf("\nLinked list 1\n");
    display(head1);
    head2 = insertAtHead(head2, 70);
    head2 = insertAtHead(head2, 60);
    head2 = insertAtHead(head2, 30);
    head2 = insertAtHead(head2, 20);
    head2 = insertAtHead(head2, 50);

    printf("\nLinked list 2\n");
    display(head2);

    findUnion(head1, head2);
    sortLinkedList(list3);

    printf("\n\nLinked list 3 - Union of list 1 and list 2\n");
    display(list3);
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
    if (head == NULL)
    {
        printf("List empty");
        return;
    }
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
