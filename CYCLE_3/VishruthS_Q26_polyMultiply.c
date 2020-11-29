//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 3 QUESTION 6
//To perform multiplication of 2 polynomials using singly linked lists

#include <stdio.h>
#include <stdlib.h>

// Node contains power,coeff and link to next node
struct Node
{
    int power, coeff;
    struct Node *link;
};

// Additional functions for input and output
struct Node *insertNode(struct Node *, int, int);
struct Node *inputPoly(struct Node *, int);
void display(struct Node *);

// ======= FUNCTION TO MULTIPLY 2 POLYNOMIALS ============ //
struct Node *Multiply(struct Node *poly1, struct Node *poly2)
{
    struct Node *prod = NULL;
    int coeff, power;
    for (struct Node *i = poly1; i != NULL; i = i->link)
        for (struct Node *j = poly2; j != NULL; j = j->link)
        {
            coeff = i->coeff * j->coeff;           // coefficients are multiplied
            power = i->power + j->power;           // powers are added
            prod = insertNode(prod, coeff, power); // and inserted into product linked list
        }
    return prod;
}

// ========= FUNCTION TO INSERT A NODE INTO RESULT ========== //
struct Node *insertNode(struct Node *prod, int coeff, int power)
{
    struct Node *curr = prod;
    while (curr != NULL) // Frst, traversing through the product list
    {
        if (curr->power == power) // and checking if any power matches
        {
            curr->coeff += coeff; // if yes, then coefficents are added
            return prod;          // And return out of the function
        }
        curr = curr->link;
    }
    // If it reaches here, it means that no term with the given power exists,
    // Hence a new node must be inserted in the appropriate position
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // creating a new node
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->link = NULL;

    if (prod == NULL)   // If it is the first node in list
        return newNode; // Then it is the head node, return it

    // Otherwise, traverse the list till the correct position is found and then insert it
    curr = prod;
    struct Node *prev = NULL;
    struct Node *next = NULL;
    while (curr != NULL && power < curr->power) // Traversing till current power less than the power in list (to maintain descending order)
    {
        prev = curr; // pointer to previous node
        curr = curr->link;
        next = curr; // pointer to next node
    }
    if (prev == NULL) // If previous node is NULL,it means it is the highest power, then it should be the first element in list
    {
        newNode->link = prod;
        prod = newNode;
    }
    else // Otherwise, it is inserted in its appropriate position
    {
        newNode->link = next;
        prev->link = newNode;
    }
    return prod;
}

// ========== MAIN FUNCTION ========= //
int main()
{
    struct Node *head1 = NULL, *head2 = NULL, *prod = NULL;
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
    
    printf("\nResult of Multiplication: ");
    prod = Multiply(head1, head2);
    display(prod);

    printf("\n");
    return 0;
}

// ========== Additional functions ============= //
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
