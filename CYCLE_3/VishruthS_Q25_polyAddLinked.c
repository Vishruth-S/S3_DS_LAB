//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 3 QUESTION 5
//To perform addition of 2 polynomials using singly linked lists

#include <stdio.h>
#include <stdlib.h>

// Node contains data and link to next node
struct Node
{
    int power;
    int coeff;
    struct Node *link;
};

// Additional functions for input and output
struct Node *insertNode(struct Node *, int, int);
struct Node *inputPoly(struct Node *, int);
void display(struct Node *);

// Head pointer to result linked list
struct Node *head3 = NULL;

// ======== FUNCTION TO CALCULATE SUM ============ //
void CalculateSum(struct Node *ptr1, struct Node *ptr2)
{
    struct Node *ptr3 = head3;
    int sum, power;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->power == ptr2->power) // If powers are same
        {
            sum = ptr1->coeff + ptr2->coeff; // Then coefficients are added
            power = ptr1->power;
            ptr3 = insertNode(ptr3, sum, power); // Inserted into resulting linked list
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if (ptr1->power > ptr2->power) // If power of first > second
        {
            sum = ptr1->coeff;
            power = ptr1->power;
            ptr3 = insertNode(ptr3, sum, power); // Then this first node is copied, so as to maintain descending order
            ptr1 = ptr1->link;
        }
        else // Else if power of first < second
        {
            sum = ptr2->coeff;
            power = ptr2->power;
            ptr3 = insertNode(ptr3, sum, power); // Then this second node is copied, so as to maintain descending order
            ptr2 = ptr2->link;
        }
    }
    while (ptr1 != NULL) // Copy remaining elements of first polynomial, if any
    {
        sum = ptr1->coeff;
        power = ptr1->power;
        ptr3 = insertNode(ptr3, sum, power);
        ptr1 = ptr1->link;
    }
    while (ptr2 != NULL) // Copy remaining elemenrs of second polynomial, if any
    {
        sum = ptr2->coeff;
        power = ptr2->power;
        ptr3 = insertNode(ptr3, sum, power);
        ptr2 = ptr2->link;
    }
}

// ==== MAIN FuNCTION ==== //
int main()
{
    struct Node *head1 = NULL, *head2 = NULL;
    int size1;
    int size2;

    printf("\nEnter number of terms of first polynomial  ");
    scanf("%d", &size1);
    if (size1 < 1)
    {
        printf("\nInvalid size");
        return 0;
    }
    head1 = inputPoly(head1, size1);

    printf("\nEnter number of terms of second polynomial  ");
    scanf("%d", &size2);
    if (size2 < 1)
    {
        printf("\nInvalid size");
        return 0;
    }
    head2 = inputPoly(head2, size2);

    printf("\nFirst polynomial: ");
    display(head1);
    printf("\nSecond polynomial: ");
    display(head2);
    printf("\nResult of addition: ");

    CalculateSum(head1, head2);
    display(head3);

    return 0;
}

// ========== Additional functions ========= //

// Function to insert a new node into result polynomial
struct Node *insertNode(struct Node *ptr, int sum, int power)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = sum;
    newNode->power = power;
    newNode->link = NULL;
    if (head3 == NULL)
        head3 = newNode;
    else
        ptr->link = newNode;
    ptr = newNode;

    return ptr;
}

// Function to input a polynomial
struct Node *inputPoly(struct Node *head, int size)
{
    struct Node *ptr = NULL;
    int power, coeff;
    printf("\nEnter the coeffiecent and power of polynomial, in descending order of power");
    printf("\nFor example: 3X^(5) + 4x^(2) + x + 6 is entered as 3 5 4 2 1 1 6 0\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &coeff);
        scanf("%d", &power);
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->power = power;
        newNode->coeff = coeff;
        newNode->link = NULL;
        if (head == NULL)
            head = newNode;
        else
            ptr->link = newNode;
        ptr = newNode;
    }
    return head;
}

// Function to display polynomial
void display(struct Node *ptr)
{
    while (ptr != NULL)
    {
        ptr->power != 0 ? printf(" %dx^(%d)", ptr->coeff, ptr->power) : printf(" %d", ptr->coeff);
        (ptr->link != NULL && ptr->link->coeff > 0) ? printf(" +") : printf("");
        ptr = ptr->link;
    }
}
