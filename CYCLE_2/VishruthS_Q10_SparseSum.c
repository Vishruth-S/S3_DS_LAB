//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 2 QUESTION 10
//PROGRAM TO CONVERT 2 SPARSE MATRICES TO TUPLE FORM
//AND FIND THEIR SUM. PRINT BOTH TUPLE AND NORMAL FORM OF SUM

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

//SUM MATRIX STRUCTURE AND SIZE
struct Sparse_matrix sparseSum[MAX_TERMS];
int SUM_SIZE;

//SIZE OF ROWS AND COLS OF INPUT MATRIX & RESULT MATRIX
const int MATRIX_ROWS, MATRIX_COLS;
int matrix1[100][100], matrix2[100][100], matrixSum[100][100];

//FUNCTION TO PRINT 2D MATRIX (NORMAL FORM)
void printMatrix(int matrix[100][100])
{
    int i, j;
    for (i = 0; i < MATRIX_ROWS; i++)
    {
        for (j = 0; j < MATRIX_COLS; j++)
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
    //FIRST ROW IS META-DATA: < no.of rows, no.of cols, no.of non-zero entries >
    sparse1[0].row = sparse2[0].row = MATRIX_ROWS;
    sparse1[0].col = sparse2[0].col = MATRIX_COLS;
    int i, j, k1 = 1, k2 = 1;
    for (i = 0; i < MATRIX_ROWS; i++)
    {
        for (j = 0; j < MATRIX_COLS; j++)
        {
            if (matrix1[i][j])
            {
                sparse1[k1].row = i + 1;
                sparse1[k1].col = j + 1;
                sparse1[k1].value = matrix1[i][j];
                k1++;
            }
            if (matrix2[i][j])
            {
                sparse2[k2].row = i + 1;
                sparse2[k2].col = j + 1;
                sparse2[k2].value = matrix2[i][j];
                k2++;
            }
        }
    }
    SIZE1 = k1;
    sparse1[0].value = k1 - 1;
    SIZE2 = k2;
    sparse2[0].value = k2 - 1;
}

//FUNCTION TO CALCULATE SUM
void CalculateSum()
{
    //FIRST ROW IS META-DATA: < no.of rows, no.of cols, no.of non-zero entries >
    sparseSum[0].row = sparse1[0].row;
    sparseSum[0].col = sparse1[0].col;
    int i = 1, j = 1, k = 1;
    while (i < SIZE1 && j < SIZE2)
    {
        if (sparse1[i].row == sparse2[j].row && sparse1[i].col == sparse2[j].col) //IF SAME ROW & COL, ADD VALUES
        {
            sparseSum[k].row = sparse1[i].row;
            sparseSum[k].col = sparse1[i].col;
            sparseSum[k].value = sparse1[i].value + sparse2[j].value;
            i++;
            j++;
        }
        else if (sparse1[i].row == sparse2[j].row) //IF ROWS ARE SAME
        {
            sparseSum[k].row = sparse1[i].row;
            if (sparse1[i].col < sparse2[j].col && i < SIZE1) //IF COL1 < COL2
            {
                sparseSum[k].col = sparse1[i].col;
                sparseSum[k].value = sparse1[i].value;
                i++;
            }
            else //IF COL2 < COL1
            {
                sparseSum[k].col = sparse2[j].col;
                sparseSum[k].value = sparse2[j].value;
                j++;
            }
        }
        else //IF ROWS ARE NOT SAME
        {
            if (sparse1[i].row < sparse2[j].row) //IF ROW1 < ROW2
            {
                sparseSum[k].row = sparse1[i].row;
                sparseSum[k].col = sparse1[i].col;
                sparseSum[k].value = sparse1[i].value;
                i++;
            }
            else //IF ROW2 < ROW1
            {
                sparseSum[k].row = sparse2[j].row;
                sparseSum[k].col = sparse2[j].col;
                sparseSum[k].value = sparse2[j].value;
                j++;
            }
        }
        k++;
    }
    while (i < SIZE1) //THIS LOOP IS TO FILL UP REMAINING ELEMENTS IN SPARSE1
    {
        sparseSum[k].row = sparse1[i].row;
        sparseSum[k].col = sparse1[i].col;
        sparseSum[k].value = sparse1[i].value;
        k++;
        i++;
    }
    while (j < SIZE2) //THIS LOOP IS TO FILL UP REMAINING ELEMENTS IN SPARSE2
    {
        sparseSum[k].row = sparse2[j].row;
        sparseSum[k].col = sparse2[j].col;
        sparseSum[k].value = sparse2[j].value;
        k++;
        j++;
    }
    SUM_SIZE = k;
    sparseSum[0].value = k - 1;
}

//CONVERT TUPLE FORM BACK TO 2D MATRIX
void convertSparseToNormal()
{
    int i, j;
    //INITILIAZE SUM MATRIX WITH ALL ELEMENTS 0
    for (i = 0; i < MATRIX_COLS; i++)
        for (j = 0; j < MATRIX_ROWS; j++)
            matrixSum[i][j] = 0;

    for (i = 1; i < SUM_SIZE; i++)
    {
        matrixSum[sparseSum[i].row - 1][sparseSum[i].col - 1] = sparseSum[i].value;
    }
}

int main()
{
    int i, j, row2, col2;
    printf("\nEnter Dimensions of matrix 1\n");
    scanf("%d%d", &MATRIX_ROWS, &MATRIX_COLS);
    printf("\nEnter Elements of matrix 1\n");
    for (i = 0; i < MATRIX_ROWS; i++)
        for (j = 0; j < MATRIX_COLS; j++)
            scanf("%d", &matrix1[i][j]);

    printf("\nEnter Dimensions of matrix 2\n");
    scanf("%d%d", &row2, &col2);
    if (row2 != MATRIX_ROWS || col2 != MATRIX_COLS)
    {
        printf("\nInvalid dimensions for addition\n");
        return 0;
    }
    printf("\nEnter Elements of matrix 2\n");
    for (i = 0; i < MATRIX_ROWS; i++)
        for (j = 0; j < MATRIX_COLS; j++)
            scanf("%d", &matrix2[i][j]);

    printf("\nEntered matrix 1\n");
    printMatrix(matrix1);
    printf("\nEntered matrix 2\n");
    printMatrix(matrix2);

    convertToSparseMatrix();

    printf("\nSparse Matrix 1 (Tuple form)");
    printSparseMatrix(sparse1, SIZE1);
    printf("\n\nSparse Matrix 2 (Tuple form)");
    printSparseMatrix(sparse2, SIZE2);

    CalculateSum();

    printf("\n\nSum of Sparse Matrices (Tuple form)");
    printSparseMatrix(sparseSum, SUM_SIZE);

    convertSparseToNormal();
    printf("\n\nSum of matrices (Normal form)\n");
    printMatrix(matrixSum);

    // ======TO VERIFY RESULT========//
    // int temp[100][100];
    // for (i = 0; i < m; i++)
    //     for (j = 0; j < n; j++)
    //         temp[i][j] = arr[i][j] + arr1[i][j];

    // printf("\nActual Sum matrix is\n");
    // for (i = 0; i < m; i++)
    // {
    //     for (j = 0; j < n; j++)
    //     {
    //         printf("%d \t", temp[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;
}