#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Time complexity: O(n^2)
void selectionSort(struct Node *head)
{
    if (head == NULL)
        return;
    struct Node *curr = head, *curr2 = head, *min = NULL;
    for (; curr2; curr2 = curr2->next)
    {
        min = curr2;
        for (curr = curr2; curr; curr = curr->next)
        {
            if (curr->data < min->data)
                min = curr;
        }
        int temp = curr2->data;
        curr2->data = min->data;
        min->data = temp;
    }
}

struct Node *insertAtHead(struct Node *, int);
void display(struct Node *);

int main()
{
    struct Node *head = NULL;
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 60);
    head = insertAtHead(head, 40);
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 70);
    head = insertAtHead(head, 50);
    head = insertAtHead(head, 10);
    head = insertAtHead(head, 30);
    printf("\nLinked list \n");
    display(head);
    selectionSort(head);
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
