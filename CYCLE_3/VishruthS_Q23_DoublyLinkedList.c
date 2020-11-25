//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 3 QUESTION 3
//To implement a Doubly Linked List and perform the necessary operations

#include <stdio.h>
#include <stdlib.h>

// Node contains data and link to previous & next nodes
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Head pointer to linked list
struct Node *head = NULL;

// Function to insert element at the beginning
// Time complexity: O(1)
void insertAtBeginning(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;

    printf("\nInsertion Successful");
}

// Function to insert element at the end
// Time complexity: O(n)
void insertAtEnd(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    struct Node *end = head;
    if (end != NULL)
    {
        while (end->next != NULL)
        {
            end = end->next;
        }
        end->next = newNode;
    }
    else
        head = newNode;

    printf("\nInsertion Successful");
}

// Function to insert a node after a particular position
// Time complexity: Worst case O(n), Best case O(1)
void insertAfterPosition(int position, int data)
{
    struct Node *curr = head;
    while (curr != NULL && --position)
        curr = curr->next;
    if (curr == NULL)
    {
        printf("\nPosition exceeded list size");
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *nextNode = curr->next;
    newNode->data = data;
    newNode->prev = curr;
    newNode->next = curr->next;
    curr->next = newNode;
    if (nextNode != NULL)
        nextNode->prev = newNode;
    printf("\nInsertion Successful");
}

// Function to delete a particular node
// Time complexity: Worst case O(n), Best case O(1)
void deleteElement(int element)
{
    struct Node *curr = head;
    while (curr != NULL && curr->data != element)
        curr = curr->next;
    if (curr == NULL)
    {
        printf("\nElement not found");
        return;
    }
    struct Node *previusNode, *nextNode;
    previusNode = curr->prev;
    nextNode = curr->next;
    if (previusNode == NULL)
        head = nextNode;
    else
        previusNode->next = nextNode;
    if (nextNode != NULL)
        nextNode->prev = previusNode;

    free(curr);
    printf("\nDeletion Successful");
}

void display();
void display_reverse();

int main()
{
    int ch, element, pos;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Insert at beginning");
        printf("\n2.Insert at end");
        printf("\n3.Insert at position");
        printf("\n4.Delete node containing a particular element ");
        printf("\n5.Display linked list");
        printf("\n6.Display linked list in reverse order");

        printf("\n\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            insertAtBeginning(element);
            break;
        case 2:
            printf("\nEnter element to insert  ");
            scanf("%d", &element);
            insertAtEnd(element);
            break;
        case 3:
            printf("\nEnter the position after which node will be inserted ");
            scanf("%d", &pos);
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            insertAfterPosition(pos, element);
            break;
        case 4:
            printf("\nEnter element to delete ");
            scanf("%d", &element);
            deleteElement(element);
            break;
        case 5:
            display();
            break;
        case 6:
            display_reverse();
            break;
        }
    } while (ch < 7);
    return 0;
}

// Function to display elements
void display()
{
    printf("\n");
    struct Node *ptr = head;
    if (ptr == NULL)
    {
        printf("\nList empty");
        return;
    }
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// Function to display elements in reverse order --- (To verify that list is doubly linked)
void display_reverse()
{
    printf("\n");
    struct Node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
}
