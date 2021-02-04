// Given single circular linked list containing a set of data. Obtain the following from this data structure
// i) For given two elements in the list, find the distance(that is, the number of nodes) between the two.
// ii) Reverse the direction of links

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *last = NULL;

// Time complexity: O(n), Space complexity: O(1)
int findDistance(int data1, int data2)
{
    if (last == NULL || data1 == data2) // base case, if only no node or same node
        return 0;

    struct Node *curr = last->next;
    while (curr != last && curr->data != data1) // go to the first node
        curr = curr->next;

    if (curr == last && curr->data != data1) // this is to handle the case if the required first node doesn't exist
        return -1;

    int count = 0; // intiliaze distance as 0
    struct Node *curr2 = curr->next;
    while (curr2 != curr && curr2->data != data2) // traverse till the next required node is found
    {
        curr2 = curr2->next;
        count++; // and keep updating the distance
    }
    if (curr == curr2 && curr2->data != data2) // this is to handle the case if the required second node doesn't exist
        return -1;

    return count;
}

// Time complexity: O(n), Space complexity: O(1)
struct Node *reverseList(struct Node *head)
{
    struct Node *curr = head, *prev = last, *next = NULL;
    do
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != head);
    head->next = prev;
    head = prev;

    return head;
}

void display();
struct Node *insertAtHead(struct Node *, int);

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
    printf("\nCircular linked list\n");
    display(head);

    // head = reverseList(head);
    // printf("\nReversed\n");
    // display(head);

    int d1, d2;
    printf("\nEnter data of first node\n");
    scanf("%d", &d1);
    printf("Enter data of second node\n");
    scanf("%d", &d2);

    int dist = findDistance(d1, d2);
    if (dist == -1)
        printf("\nOne of the entered nodes doesn't exist in list\n");
    else
        printf("\nNumber of nodes between %d and %d is: %d", d1, d2, dist);
}

struct Node *insertAtHead(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    if (last == NULL)
        last = newNode;
    else
        newNode->next = last->next;
    last->next = newNode;

    return newNode;
}

void display(struct Node *head)
{
    if (head == NULL)
        return;

    struct Node *ptr = head;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}