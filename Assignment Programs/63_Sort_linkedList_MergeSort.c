// Sort a linked list using Merge Sort

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *getMiddle(struct Node *);
struct Node *merge(struct Node *, struct Node *);

// Time complexity: O(NlogN), Space complexity: O(logN)
struct Node *mergeSort(struct Node *head)
{
    if (head == NULL || head->next == NULL) // base case
        return head;

    struct Node *left, *right, *temp;
    // split into two linked lists
    left = head;
    right = getMiddle(head);
    temp = right->next;
    right->next = NULL;
    right = temp;

    // Recursively sort left and right sub-lists
    left = mergeSort(left);
    right = mergeSort(right);
    // Merge the sorted lists
    return merge(left, right);
}

struct Node *merge(struct Node *list1, struct Node *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    struct Node *dummyNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *curr = dummyNode;
    while (list1 && list2)
    {
        if (list1->data <= list2->data)
        {
            curr->next = list1;
            list1 = list1->next;
        }
        else
        {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }
    if (list1)
        curr->next = list1;
    if (list2)
        curr->next = list2;

    return dummyNode->next;
}

struct Node *getMiddle(struct Node *head)
{
    struct Node *slow = head, *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct Node *insertAtHead(struct Node *, int);
void display(struct Node *);

int main()
{
    struct Node *head = NULL;
    head = insertAtHead(head, 60);
    head = insertAtHead(head, 30);
    head = insertAtHead(head, 50);
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 70);
    head = insertAtHead(head, 10);
    head = insertAtHead(head, 40);
    printf("\nLinked list\n");
    display(head);
    head = mergeSort(head);
    printf("\nLinked list After Sorting\n");
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
