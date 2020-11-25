//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 3 QUESTION 4
//To implement a Circular Linked List and perform the necessary operations

#include <stdio.h>
#include <stdlib.h>

// Node contains data and link to  next node
struct Node
{
    int data;
    struct Node *link;
};

// Last pointer to linked list, pointing to last element
struct Node *last = NULL;

// Function to insert element at the beginning
// Time complexity: O(1)
void insertAtBeginning(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (last == NULL)
        last = newNode;
    else
        newNode->link = last->link;
    last->link = newNode;
    printf("\nInsertion successful");
}

// Function to insert element at the end
// Time complexity: O(1)
void insertAtEnd(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (last == NULL)
    {
        last = newNode;
        last->link = newNode;
    }
    else
    {
        newNode->link = last->link;
        last->link = newNode;
        last = newNode;
    }
    printf("\nInsertion successful");
}

// Function to insert element after a particular position
// Time complexity: Worst case O(n), Best case O(1)
void insertAfterPosition(int position, int data)
{
    if (last == NULL)
    {
        printf("\nList empty");
        return;
    }

    struct Node *curr = last->link;
    while (--position)
    {
        curr = curr->link;
        if (curr == last->link)
        {
            printf("\nPosition exceeded list size");
            return;
        }
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = curr->link;
    curr->link = newNode;
    if (curr == last)
        last = newNode;

    printf("\nInsertion successful");
}

// Function to delete a particular node
// Time complexity: Worst case O(n), Best case O(1)
void deleteElement(int element)
{
    if (last == NULL)
    {
        printf("\nList empty");
        return;
    }

    struct Node *prev = last;
    struct Node *curr = last->link;
    while (curr->data != element)
    {
        prev = curr;
        curr = curr->link;
        if (curr == last->link)
        {
            printf("\nElement not found");
            return;
        }
    }
    prev->link = curr->link;
    if (curr == last)
        last = prev;
    if (curr == prev)
        last = NULL;

    free(curr);
    printf("\nDeletion successful");
}

void display();

// MAIN FUNCTION
int main()
{
    insertAtBeginning(10);
    insertAtBeginning(20);
    display();
    insertAfterPosition(1, 25);
    insertAfterPosition(2, 15);
    insertAfterPosition(3, 45);
    display();
    deleteElement(10);
    display();
    deleteElement(15);
    display();
    deleteElement(45);
    display();
    insertAfterPosition(5, 13);
    deleteElement(13);
    display();
    return 0;
}

// Function to display elements
void display()
{
    if (last == NULL)
    {
        printf("\nList empty");
        return;
    }
    struct Node *ptr = last->link;
    printf("\n");
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    } while (ptr != last->link);
}