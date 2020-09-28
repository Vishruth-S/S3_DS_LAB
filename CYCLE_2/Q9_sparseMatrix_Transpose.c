//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 2 QUESTION 9
//PROGRAM TO CONVERT A SPARSE MATRIX TO TUPLE FORM AND PRINT IT
//AND FIND ITS TRANPOSE. PRINT BOTH TUPLE AND ORIGINAL FORM OF TRANSPOSE

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
struct Sparse_matrix transposeSparse[MAX_TERMS];
int SIZE;

//SIZE OF ROWS AND COLS OF INPUT MATRIX
const int MATRIX_ROWS, MATRIX_COLS;

//INPUT MATRIX AND TRANSPOSE
int matrix[100][100];
int transpose[100][100];

//FUNCTION TO PRINT MATRIX IN 2D NORMAL ARRAY FORM
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

//FUNCTION TO PRINT SPARSE MATRIX (TUPLE FORM)
void printSparseMatrix(struct Sparse_matrix sparse[100])
{
    int i;
    printf("\n");
    printf("ROW  COLUMN  VALUE");
    for (i = 0; i < SIZE; i++)
    {
        printf("\n");
        printf("%d\t%d\t%d", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

//CONVERT INPUT MATRIX TO SPARSE MATRIX (TUPLE FORM)
void convertToSparseMatrix()
{
    //FIRST ROW IS META-DATA: < no.of rows, no.of cols, no.of non-zero entries >
    sparse1[0].row = MATRIX_ROWS;
    sparse1[0].col = MATRIX_COLS;
    int i, j, k = 1;
    for (i = 0; i < MATRIX_ROWS; i++)
    {
        for (j = 0; j < MATRIX_COLS; j++)
        {
            if (matrix[i][j])
            {
                sparse1[k].row = i + 1; // +1 since tuple is 1 based indexing
                sparse1[k].col = j + 1;
                sparse1[k].value = matrix[i][j];
                k++;
            }
        }
    }
    SIZE = k;
    sparse1[0].value = k - 1; //value = no.of non-zero elements = k-1
}

//FIND TRANSPOSE OF SPARSE MATRIX
void transposeSparseMatrix()
{
    //FIRST ROW IS META-DATA: < no.of rows, no.of cols, no.of non-zero entries >
    transposeSparse[0].row = MATRIX_COLS; //rows and cols are interchanged
    transposeSparse[0].col = MATRIX_ROWS;
    transposeSparse[0].value = sparse1[0].value; //value will be same for transpose
    int i, j, k = 1, min_col;
    for (i = 1; i <= MATRIX_COLS; i++)
    {
        for (j = 1; j <= SIZE; j++)
        {
            if (sparse1[j].col == i)
            {
                transposeSparse[k].row = sparse1[j].col;
                transposeSparse[k].col = sparse1[j].row;
                transposeSparse[k].value = sparse1[j].value;
                k++;
            }
        }
    }
}

//CONVERT TUPLE FORM BACK TO 2D MATRIX
void convertSparseToNormal()
{
    int i, j;
    //INITILIAZE TRANSPOSE ARRAY WITH ALL ELEMENTS 0
    for (i = 0; i < MATRIX_COLS; i++)
        for (j = 0; j < MATRIX_ROWS; j++)
            transpose[i][j] = 0;

    //transpose[row][col] = Tuple[i].value (-1 is added since tuple is 1 based indexing)
    for (i = 1; i < SIZE; i++)
    {
        transpose[transposeSparse[i].row - 1][transposeSparse[i].col - 1] = transposeSparse[i].value;
    }
}

int main()
{
    int i, j;
    printf("\nEnter matrix dimensions: ");
    scanf("%d %d", &MATRIX_ROWS, &MATRIX_COLS);
    printf("\nEnter matrix: ");
    for (i = 0; i < MATRIX_ROWS; i++)
        for (j = 0; j < MATRIX_COLS; j++)
            scanf("%d", &matrix[i][j]);

    printf("\nINPUT MATRIX\n");
    printMatrix(matrix, MATRIX_ROWS, MATRIX_COLS);

    convertToSparseMatrix();

    printf("\n\nSPARSE MATRIX (TUPLE FORM)");
    printSparseMatrix(sparse1);

    printf("\n\nTRANSPOSE OF SPARSE MATRIX (TUPLE FORM)");
    transposeSparseMatrix();
    printSparseMatrix(transposeSparse);

    printf("\n\nTRANSPOSE OF INPUT MATRIX\n");
    convertSparseToNormal();
    printMatrix(transpose, MATRIX_COLS, MATRIX_ROWS);
    return 0;
}