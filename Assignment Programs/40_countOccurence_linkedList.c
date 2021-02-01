// program to count occurence of a given element in a linked list
// And also count the number of non-zero elements

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// TC - o(n)
int countOccurrences(struct Node *head, int query)
{
    if (head == NULL)
        return 0;
    return ((head->data == query) + countOccurrences(head->next, query));
    // The above line is a shorter way of writing -
    // if(head->data == query) return 1 + countOccurences(head->next, query);
    // else return countOccurences(head->next, query);
}

// TC - o(n)
int countNonZeroNodes(struct Node *head)
{
    if (head == NULL)
        return 0;
    return ((head->data != 0) + countNonZeroNodes(head->next));
}

struct Node *insertAtHead(struct Node *, int);
void display(struct Node *);

int main()
{
    struct Node *head = NULL;
    head = insertAtHead(head, 6);
    head = insertAtHead(head, 0);
    head = insertAtHead(head, 0);
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 0);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 0);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 1);
    printf("\nLinked list\n");
    display(head);
    int n;
    printf("\nEnter the data of the node whose succesor is to be found\n");
    scanf("%d", &n);
    int count = countOccurrences(head, n);
    printf("\nCount of %d is %d", n, count);

    int nonZero = countNonZeroNodes(head);
    printf("\nCount of non-zero nodes is %d", nonZero);
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
