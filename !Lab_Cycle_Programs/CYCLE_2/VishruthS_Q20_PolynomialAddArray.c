//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 2 QUESTION 20
//To add two polynomials in one variable using arrays

#include <stdio.h>

void polyAdd(int poly1[], int poly2[], int size1, int size2)
{
    const int size3 = size1 > size2 ? size1 : size2; // size pf result is max(size1,size2)
    int result[10] = {0};                            // result array, initializng all values to 0
    for (int i = 0; i <= size1; i++)
        result[i] = poly1[i]; // Copying first polynomial
    for (int i = 0; i <= size2; i++)
        result[i] += poly2[i]; // Adding second polynomial

    printf("\nResult of addition: ");
    for (int i = 0; i <= size3; i++)
        printf("%d ", result[i]);
}

int main()
{
    int poly1[10], poly2[10];
    int size1;
    int size2;
    
    printf("\nEnter degree of first polynomial  ");
    scanf("%d", &size1);
    printf("\nEnter the coeffecients of first polynomial\n");
    for (int i = 0; i <= size1; i++)
        scanf("%d", &poly1[i]);
    printf("\nEnter degree of second polynomial   ");
    scanf("%d", &size2);
    printf("\nEnter the coeffecients of second polynomial\n");
    for (int i = 0; i <= size2; i++)
        scanf("%d", &poly2[i]);

    polyAdd(poly1, poly2, size1, size2);

    return 0;
}