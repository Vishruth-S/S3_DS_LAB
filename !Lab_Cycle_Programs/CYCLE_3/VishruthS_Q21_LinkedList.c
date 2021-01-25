//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 3 QUESTION 1
//To implement a singly linked list and perform the necessary operations

#include <stdio.h>
#include <stdlib.h>

// Node contains data and link to next node
struct Node
{
    int data;
    struct Node *link;
};

// Head pointer to linked list
struct Node *head = NULL;

// Function to insert element at the beginning
// Time complexity: O(1)
void insertAtBeginning(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = head;
    head = newNode;

    printf("\nInsertion Successful");
}

// Function to insert element at the end
// Time complexity: O(n)
void insertAtEnd(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = NULL;
    struct Node *end = head;
    if (end != NULL)
    {
        while (end->link != NULL)
        {
            end = end->link;
        }
        end->link = newNode;
    }
    else
        head = newNode;

    printf("\nInsertion Successful");
}

// Function to insert element after a particular position
// Time complexity: Worst case O(n), Best case O(1)
void insertAfterPosition(int position, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = NULL;
    struct Node *curr = head;
    while (curr != NULL && --position)
        curr = curr->link;
    if (curr == NULL)
    {
        printf("\nPosition exceeded list size");
        return;
    }
    newNode->link = curr->link;
    curr->link = newNode;

    printf("\nInsertion Successful");
}

// Function to delete a particular node
// Time complexity: Worst case O(n), Best case O(1)
void deleteElement(int element)
{
    struct Node *curr = head, *prev = NULL;
    while (curr != NULL && curr->data != element)
    {
        prev = curr;
        curr = curr->link;
    }
    if (curr == NULL)
    {
        printf("\nElement not found");
        return;
    }
    if (prev == NULL)
        head = head->link;
    else
        prev->link = curr->link;

    free(curr);
    printf("\nDeletion Successful");
}

void display();

// MAIN FUNCTION
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
        }
    } while (ch < 6);

    return 0;
}

// Function to display elements
void display()
{
    struct Node *ptr = head;
    if (ptr == NULL)
    {
        printf("\nList empty");
        return;
    }
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}
