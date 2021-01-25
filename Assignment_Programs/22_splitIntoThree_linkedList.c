// for a given linked list ann any input K,
// split the list into three lists LIST1, LIST2 and LIST3 such that the
// elements in LIST1 is less than the value K,
// the elements in LIST2  is equal to the value K
// and the elements in LIST3 is greater than the value K.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *list1 = NULL, *list2 = NULL, *list3 = NULL;

void splitIntoThree(struct Node *head, int k)
{
    struct Node *curr1 = list1, *curr2 = list2, *curr3 = list3;
    for (struct Node *curr = head; curr; curr = curr->next)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = curr->data;
        newNode->next = NULL;

        if (curr->data < k)
        {
            if (list1 == NULL)
                list1 = newNode;
            else
                curr1->next = newNode;
            curr1 = newNode;
        }
        else if (curr->data == k)
        {
            if (list2 == NULL)
                list2 = newNode;
            else
                curr2->next = newNode;
            curr2 = newNode;
        }
        else
        {
            if (list3 == NULL)
                list3 = newNode;
            else
                curr3->next = newNode;
            curr3 = newNode;
        }
    }
}

struct Node *insertAtHead(struct Node *, int);
void display(struct Node *);

int main()
{
    struct Node *head = NULL;
    head = insertAtHead(head, 9);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 7);
    head = insertAtHead(head, 7);
    head = insertAtHead(head, 8);
    head = insertAtHead(head, 6);
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 1);
    printf("\nLinked list\n");
    display(head);
    int k;
    printf("\nEnter value of k\n");
    scanf("%d", &k);
    splitIntoThree(head, k);
    printf("\nLinked list 1\n");
    display(list1);
    printf("\nLinked list 2\n");
    display(list2);
    printf("\nLinked list 3\n");
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
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
