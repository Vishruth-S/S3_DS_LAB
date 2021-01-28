// program to insert elements into sorted linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Time complexity: O(m+n), Space complexity: O(1), since no extra list is created
struct Node *mergeListsInPlace(struct Node *list1, struct Node *list2)
{
    struct Node *head3 = NULL, *curr = NULL;
    if (!list1)
        return list2;
    if (!list2)
        return list1;
    if (list1->data <= list2->data)
    {
        curr = list1;
        list1 = curr->next;
    }
    else
    {
        curr = list2;
        list2 = list2->next;
    }
    head3 = curr;
    while (list1 && list2)
    {
        if (list1->data <= list2->data)
        {
            curr->next = list1;
            curr = list1;
            list1 = list1->next;
        }
        else
        {
            curr->next = list2;
            curr = list2;
            list2 = list2->next;
        }
    }
    if (list1)
        curr->next = list1;
    if (list2)
        curr->next = list2;

    return head3;
}

// Slight modification of above, makes code shorter and simpler
struct Node *mergeListsInPlace2(struct Node *list1, struct Node *list2)
{
    if (!list1)
        return list2;
    if (!list2)
        return list1;
    struct Node *dummyHead = (struct Node *)malloc(sizeof(struct Node));
    struct Node *curr = dummyHead;
    while (list1 && list2)
    {
        if (list1->data <= list2->data)
        {
            curr->next = list1;
            curr = list1;
            list1 = list1->next;
        }
        else
        {
            curr->next = list2;
            curr = list2;
            list2 = list2->next;
        }
    }
    if (list1)
        curr->next = list1;
    if (list2)
        curr->next = list2;

    return dummyHead->next;
}

struct Node *insertInSortedList(struct Node *, int);
void display(struct Node *);

int main()
{
    struct Node *head1 = NULL, *head2 = NULL;

    head1 = insertInSortedList(head1, 10);
    head1 = insertInSortedList(head1, 20);
    head1 = insertInSortedList(head1, 30);
    head1 = insertInSortedList(head1, 40);

    head2 = insertInSortedList(head2, 12);
    head2 = insertInSortedList(head2, 23);
    head2 = insertInSortedList(head2, 25);
    head2 = insertInSortedList(head2, 35);
    head2 = insertInSortedList(head2, 45);
    printf("\nLinked list 1\n");
    display(head1);
    printf("\nLinked list 2\n");
    display(head2);

    head1 = mergeListsInPlace(head1, head2);
    printf("\nList 1 after merging list 2\n");
    display(head1);
    return 0;
}

struct Node *insertInSortedList(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
        return newNode;

    if (data < head->data)
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

void display(struct Node *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}