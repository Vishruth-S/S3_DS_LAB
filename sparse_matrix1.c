#include <stdio.h>
#define MAX_TERMS 100

struct Sparse_matrix
{
    int row;
    int col;
    int value;
};

//SPARSE MATRIX STRUCTURE AND SIZE
struct Sparse_matrix terms[MAX_TERMS];
int SIZE;

//SIZE OF ROWS AND COLS OF INPUT MATRIX
const int MATRIX_ROWS, MATRIX_COLS;

//INPUT MATRIX AND TRANSPOSE
int matrix[100][100];
int transpose[100][100];

//PRINT 2D MATRIX
void printMatrix(int printMatrix[100][100], int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%4d", printMatrix[i][j]);
        }
        printf("\n");
    }
}

//CONVERT NORMAL MATRIX TO SPARSE MATRIX
void convertToSparseMatrix()
{
    int i, j, k = 0;
    for (i = 0; i < MATRIX_ROWS; i++)
    {
        for (j = 0; j < MATRIX_COLS; j++)
        {
            if (matrix[i][j])
            {
                terms[k].row = i + 1;
                terms[k].col = j + 1;
                terms[k].value = matrix[i][j];
                k++;
            }
        }
    }
    SIZE = k;
}

//FIND TRANSPOSE OF SPARSE MATRIX
void transposeSparseMatrix()
{
    int i, temp;
    for (i = 0; i < SIZE; i++)
    {
        temp = terms[i].row;
        terms[i].row = terms[i].col;
        terms[i].col = temp;
    }
}

//CONVERT TUPLE FORM BACK TO 2D
void convertSparseToNormal()
{
    int i, j;
    //INITILIAZE TRANSPOSE ARRAY WITH ALL ELEMENTS 0
    for (i = 0; i < MATRIX_COLS; i++)
        for (j = 0; j < MATRIX_ROWS; j++)
            transpose[i][j] = 0;

    //transpose[row][col] = value (-1 is added since tuple is 1 based indexing)
    for (i = 0; i < SIZE; i++)
    {
        transpose[terms[i].row - 1][terms[i].col - 1] = terms[i].value;
    }
}

// PRINT SPARSE MATRIX (TUPLE FORM)
void printSparseMatrix()
{
    int i;
    printf("ROW  COLUMN  VALUE");
    for (i = 0; i < SIZE; i++)
    {
        printf("\n");
        printf("%d\t%d\t%d", terms[i].row, terms[i].col, terms[i].value);
    }
}

int main()
{
    int i, j;
    printf("\nEnter matrix dimensions: ");
    scanf("%d %d", &MATRIX_ROWS, &MATRIX_COLS);
    // int arr[MATRIX_ROWS][MATRIX_COLS];
    printf("\nEnter matrix: ");
    for (i = 0; i < MATRIX_ROWS; i++)
        for (j = 0; j < MATRIX_COLS; j++)
            scanf("%d", &matrix[i][j]);

    printf("\nINPUT MATRIX\n");
    printMatrix(matrix, MATRIX_ROWS, MATRIX_COLS);
    convertToSparseMatrix();
    printf("\n\nSPARSE MATRIX (TUPLE FORM)\n");
    printSparseMatrix();
    printf("\n\nTRANSPOSE OF SPARSE MATRIX (TUPLE FORM)\n");
    transposeSparseMatrix();
    printSparseMatrix();
    convertSparseToNormal();
    printf("\n\nTRANSPOSE OF INPUT MATRIX\n");
    printMatrix(transpose, MATRIX_COLS, MATRIX_ROWS);
    return 0;
}
