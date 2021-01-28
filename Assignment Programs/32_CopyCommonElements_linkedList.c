// program to copy common elements from 2 linked lists into a third linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Method 1 - Brute force
// Time complexity: O(mn), where m is size of list1 and n is size of list2, Space complexity: O(1)
struct Node *findCommon(struct Node *head1, struct Node *head2)
{
    struct Node *head3 = NULL, *curr3 = NULL;
    struct Node *curr1, *curr2;
    for (curr1 = head1; curr1; curr1 = curr1->next)
    {
        for (curr2 = head2; curr2; curr2 = curr2->next)
        {
            if (curr1->data == curr2->data)
            {
                struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
                newNode->data = curr1->data;
                newNode->next = NULL;
                if (curr3 == NULL)
                    head3 = newNode;
                else
                    curr3->next = newNode;
                curr3 = newNode;
            }
        }
    }
    return head3;
}

// Method 2 - Optimized using hashing
// Time Complexity: O(m + n),where m is size of list1 and n is size of list2, Space complexity: O(m+n)
struct Node *findCommon2(struct Node *head1, struct Node *head2)
{
    struct Node *head3 = NULL, *curr3 = NULL;
    struct Node *curr1, *curr2;
    int common[1000] = {0};

    for (curr1 = head1; curr1; curr1 = curr1->next)
        common[curr1->data] = 1;

    for (curr2 = head2; curr2; curr2 = curr2->next)
    {
        if (common[curr2->data])
        {
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = curr2->data;
            newNode->next = NULL;
            if (curr3 == NULL)
                head3 = newNode;
            else
                curr3->next = newNode;
            curr3 = newNode;
        }
    }
    return head3;
}

struct Node *insertAtHead(struct Node *, int);
void display(struct Node *);

int main()
{
    struct Node *head1 = NULL, *head2 = NULL, *head3 = NULL;
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

    head3 = findCommon2(head1, head2);
    printf("\nLinked list 3\n");
    display(head3);
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
