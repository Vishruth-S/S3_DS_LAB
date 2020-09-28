//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 2 QUESTION 11
//PROGRAM TO CONVERT 2 SPARSE MATRICES TO TUPLE FORM
//AND FIND THEIR PRODUCT. PRINT BOTH TUPLE AND NORMAL FORM OF PRODUCT

#include <stdio.h>
#define MAX_TERMS 100

struct Sparse_matrix
{
    int row;
    int col;
    int value;
};

//SPARSE MATRIX STRUCTURE AND SIZE
struct Sparse_matrix sparse1[MAX_TERMS];
struct Sparse_matrix sparse2[MAX_TERMS];
int SIZE1, SIZE2;

//Product MATRIX STRUCTURE AND SIZE
struct Sparse_matrix sparseProduct[MAX_TERMS];
int PRODUCT_SIZE;

//SIZE OF ROWS AND COLS OF INPUT MATRIX & RESULT MATRIX
int matrix1[100][100], matrix2[100][100], matrixProduct[100][100];
int MATRIX_ROWS1, MATRIX_COLS1, MATRIX_ROWS2, MATRIX_COLS2;

//FUNCTION TO PRINT 2D MATRIX (NORMAL FORM)
void printMatrix(int matrix[100][100], int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

//FUNCTION TO PRINT SPARSE MATRIX (TUPLE FORM)
void printSparseMatrix(struct Sparse_matrix sparse[100], int size)
{
    int i;
    printf("\n");
    printf("ROW  COLUMN  VALUE");
    for (i = 0; i < size; i++)
    {
        printf("\n");
        printf("%d\t%d\t%d", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

//CONVERT NORMAL MATRIX1 and MATRIX2 TO SPARSE MATRIX
void convertToSparseMatrix()
{
    int i, j, k1 = 1, k2 = 1;
    //FIRST ROW IS META-DATA: < no.of rows, no.of cols, no.of non-zero entries >
    sparse1[0].row = MATRIX_ROWS1;
    sparse1[0].col = MATRIX_COLS1;
    for (i = 0; i < MATRIX_ROWS1; i++)
    {
        for (j = 0; j < MATRIX_COLS1; j++)
        {
            if (matrix1[i][j])
            {
                sparse1[k1].row = i + 1;
                sparse1[k1].col = j + 1;
                sparse1[k1].value = matrix1[i][j];
                k1++;
            }
        }
    }
    SIZE1 = k1;
    sparse1[0].value = k1 - 1; //no.of non-zero entries

    //FIRST ROW IS META-DATA: < no.of rows, no.of cols, no.of non-zero entries >
    sparse2[0].row = MATRIX_ROWS2;
    sparse2[0].col = MATRIX_COLS2;
    for (i = 0; i < MATRIX_ROWS2; i++)
    {
        for (j = 0; j < MATRIX_COLS2; j++)
        {
            if (matrix2[i][j])
            {
                sparse2[k2].row = i + 1;
                sparse2[k2].col = j + 1;
                sparse2[k2].value = matrix2[i][j];
                k2++;
            }
        }
    }
    SIZE2 = k2;
    sparse2[0].value = k2 - 1; //no.of non-zero entries
}

void calculateProduct()
{
    struct Sparse_matrix prod[100];
    int i, j, k = 1;
    prod[0].row = sparse1[0].col;
    prod[0].col = sparse2[0].row;

    //NAIVE WAY FOR CALCULATING PRODUCT
    for (i = 1; i < SIZE1; i++)
    {
        for (j = 1; j < SIZE2; j++)
        {
            if (sparse1[i].col == sparse2[j].row)
            {
                prod[k].row = sparse1[i].row;
                prod[k].col = sparse2[j].col;
                prod[k].value = sparse1[i].value * sparse2[j].value;
                k++;
            }
        }
    }
    prod[0].value = k - 1;

    //THE ABOVE CALCULATED TUPLE HAS DUPLICATES WHOSE VALUES NEED TO BE ADDED TO GET FINAL RESULT
    //(To see this intermediate product, use: printSparseMatrix(prod, k); )

    sparseProduct[0].row = sparse1[0].col;
    sparseProduct[0].col = sparse2[0].row;
    int c = 1, sum;
    //To Remove duplicates and add their value into the final product tuple
    for (i = 1; i < k; i++)
    {
        sum = prod[i].value;
        for (j = i + 1; j < k; j++)
        {
            if (prod[i].row == prod[j].row && prod[i].col == prod[j].col && prod[j].row > 0) //Check if same row & col ,i.e, duplicate
            {
                sum += prod[j].value;
                prod[j].row = prod[j].col = -1; //flagging duplicate values so that they are no longer considered
            }
        }
        if (prod[i].row > 0) //since already considered row will be flagged as -1, we check if row>0
        {
            sparseProduct[c].row = prod[i].row;
            sparseProduct[c].col = prod[i].col;
            sparseProduct[c].value = sum;
            c++;
        }
    }
    sparseProduct[0].value = c - 1;
    PRODUCT_SIZE = c;
}

//CONVERT TUPLE FORM BACK TO 2D MATRIX
void convertSparseToNormal()
{
    int i, j;
    //INITILIAZE Product MATRIX WITH ALL ELEMENTS 0
    for (i = 0; i < MATRIX_ROWS1; i++)
        for (j = 0; j < MATRIX_COLS2; j++)
            matrixProduct[i][j] = 0;

    for (i = 1; i < PRODUCT_SIZE; i++)
    {
        matrixProduct[sparseProduct[i].row - 1][sparseProduct[i].col - 1] = sparseProduct[i].value;
    }
}

int main()
{
    int i, j;
    printf("\nEnter Dimensions of matrix 1\n");
    scanf("%d%d", &MATRIX_ROWS1, &MATRIX_COLS1);
    printf("\nEnter Elements of matrix 1\n");
    for (i = 0; i < MATRIX_ROWS1; i++)
        for (j = 0; j < MATRIX_COLS1; j++)
            scanf("%d", &matrix1[i][j]);

    printf("\nEnter Dimensions of matrix 2\n");
    scanf("%d%d", &MATRIX_ROWS2, &MATRIX_COLS2);
    if (MATRIX_COLS1 != MATRIX_ROWS2)
    {
        printf("\nInvalid dimensions for Multiplication\n");
        return 0;
    }
    printf("\nEnter Elements of matrix 2\n");
    for (i = 0; i < MATRIX_ROWS2; i++)
        for (j = 0; j < MATRIX_COLS2; j++)
            scanf("%d", &matrix2[i][j]);

    printf("\nEntered matrix 1\n");
    printMatrix(matrix1, MATRIX_ROWS1, MATRIX_COLS1);
    printf("\nEntered matrix 2\n");
    printMatrix(matrix2, MATRIX_ROWS2, MATRIX_COLS2);

    convertToSparseMatrix();

    printf("\nSparse Matrix 1 (Tuple form)");
    printSparseMatrix(sparse1, SIZE1);
    printf("\n\nSparse Matrix 2 (Tuple form)");
    printSparseMatrix(sparse2, SIZE2);

    calculateProduct();
    printf("\n\nProduct of Sparse Matrices (Tuple form)");
    printSparseMatrix(sparseProduct, PRODUCT_SIZE);

    convertSparseToNormal();
    printf("\n\nProduct of matrices (Normal form)\n");
    printMatrix(matrixProduct, MATRIX_ROWS1, MATRIX_COLS2);

    // ===========TO VERIFY RESULT============//
    // int k = 0, temp[100][100];
    // for (i = 0; i < MATRIX_ROWS1; i++)
    //     for (j = 0; j < MATRIX_COLS2; j++)
    //         for (k = 0; k < MATRIX_COLS1; k++)
    //             temp[i][j] += (matrix1[i][k] * matrix2[k][j]);
    // printf("\nPROdUCT ACTUAL (CALCULATED DIRECTLY) \n");
    // printMatrix(temp, MATRIX_ROWS1, MATRIX_COLS2);

    return 0;
}