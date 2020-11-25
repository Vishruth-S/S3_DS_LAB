//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 3 QUESTION 2
//To Reverse a singly linked list

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

// ======= REVERSE FUNCTIONS =======//

// METHOD 1: Iterative
// Time complexity: O(n)
void reverse_iterative()
{
    struct Node *prev, *current, *next;
    prev = NULL;
    current = head;
    while (current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// METHOD 2: Recursive
// Time complexity: O(n)
void reverse_recursive(struct Node *ptr)
{
    if (ptr->link == NULL)
    {
        head = ptr;
        return;
    }
    reverse_recursive(ptr->link);
    struct Node *temp = ptr->link;
    temp->link = ptr;
    ptr->link = NULL;
}

void insertAtBeginning(int);
void display();

// ==== MAIN FUNCTION ====//
int main()
{

    insertAtBeginning(12);
    insertAtBeginning(34);
    insertAtBeginning(18);
    insertAtBeginning(42);
    insertAtBeginning(15);
    insertAtBeginning(24);
    insertAtBeginning(20);

    printf("\nBefore reverse: ");
    display();

    reverse_iterative();
    // reverse_recursive();

    printf("\nAfter reverse:  ");
    display();
    return 0;
}

// ===== Auxillary functions =====//

// To insert elements at front
void insertAtBeginning(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->link = head;
    head = ptr;
}

// TO display the linked list
void display()
{
    printf("\n");
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
}