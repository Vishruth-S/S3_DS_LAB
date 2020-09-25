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

//PRINT 2D MATRIX
void printMatrix(int arr[MATRIX_ROWS][MATRIX_COLS])
{
    int i, j;
    for (i = 0; i < MATRIX_ROWS; i++)
    {
        for (j = 0; j < MATRIX_COLS; j++)
        {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
}

//CONVERT NORMAL MATRIX TO SPARSE MATRIX
void convertToSparseMatrix(int arr[MATRIX_ROWS][MATRIX_COLS])
{
    int i, j, k = 0;
    for (i = 0; i < MATRIX_ROWS; i++)
    {
        for (j = 0; j < MATRIX_COLS; j++)
        {
            if (arr[i][j])
            {
                terms[k].row = i + 1;
                terms[k].col = j + 1;
                terms[k].value = arr[i][j];
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
    int i, j, new_arr[MATRIX_ROWS][MATRIX_COLS];
    //INITILIAZE AN ARRAY WITH ALL ELEMENTS 0
    for (i = 0; i < MATRIX_ROWS; i++)
        for (j = 0; j < MATRIX_COLS; j++)
            new_arr[i][j] = 0;

    //Arr[row][col] = value (-1 is added since tuple is 1 based indexing)
    for (i = 0; i < SIZE; i++)
    {
        new_arr[terms[i].row - 1][terms[i].col - 1] = terms[i].value;
    }
    printf("\n\nTRANSPOSE OF INPUT MATRIX\n");
    printMatrix(new_arr);
}

//PRINT SPARSE MATRIX (TUPLE FORM)
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
    int arr[MATRIX_ROWS][MATRIX_COLS];
    printf("\nEnter matrix: ");
    for (i = 0; i < MATRIX_ROWS; i++)
        for (j = 0; j < MATRIX_COLS; j++)
            scanf("%d", &arr[i][j]);
    printf("\nINPUT MATRIX\n");
    printMatrix(arr);
    convertToSparseMatrix(arr);
    printf("\n\nSPARSE MATRIX (TUPLE FORM)\n");
    printSparseMatrix();
    printf("\n\nTRANSPOSE OF SPARSE MATRIX (TUPLE FORM)\n");
    transposeSparseMatrix();
    printSparseMatrix();
    convertSparseToNormal();
    return 0;
}
