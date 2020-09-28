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
struct Sparse_matrix transposeSparse2[MAX_TERMS];
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

//FIND TRANSPOSE OF SPARSE MATRIX
void transposeSparseMatrix()
{
    //FIRST ROW IS META-DATA: < no.of rows, no.of cols, no.of non-zero entries >
    transposeSparse2[0].row = MATRIX_COLS2;
    transposeSparse2[0].col = MATRIX_ROWS2;
    transposeSparse2[0].value = sparse2[0].value;
    int i, j, k = 1, min_col;
    for (i = 1; i <= MATRIX_COLS2; i++)
    {
        for (j = 1; j <= SIZE2; j++)
        {
            if (sparse2[j].col == i)
            {
                transposeSparse2[k].row = sparse2[j].col;
                transposeSparse2[k].col = sparse2[j].row;
                transposeSparse2[k].value = sparse2[j].value;
                k++;
            }
        }
    }
}

void calculateProduct(struct Sparse_matrix a[100], struct Sparse_matrix b[100], int n1, int n2)
{
    sparseProduct[0].row = sparse1[0].col;
    sparseProduct[0].col = sparse2[0].row;

    int tempRow, tempCol, sum = 0, k = 1, i, j, ii, jj;
    // struct Sparse_matrix c[100];

    //DIRECT WAY OF CALCULATING PRODUCT USING TRANSPOSE OF SECOND MATRIX
    for (i = 1; i < n1;)
    {
        tempRow = a[i].row;
        for (j = 1; j < n2;)
        {
            tempCol = b[j].row;

            sum = 0;
            for (ii = 1, jj = 1; ii < n1 && jj < n2 && a[ii].row <= tempRow && b[jj].row <= tempCol;)
            {
                if (a[ii].row != tempRow)
                    ii++;
                if (b[jj].row != tempCol)
                    jj++;
                if (a[ii].row == tempRow && b[jj].row == tempCol)
                {
                    if (a[ii].col < b[jj].col)
                        ii++;
                    else if (a[ii].col > b[jj].col)
                        jj++;
                    else
                    {
                        sum = sum + (a[ii].value * b[jj].value);
                        ii++;
                        jj++;
                    }
                }
            }

            if (sum != 0)
            {
                sparseProduct[k].row = tempRow;
                sparseProduct[k].col = tempCol;
                sparseProduct[k].value = sum;
                sum = 0;
                k++;
            }

            while (j <= n2 - 1 && b[j].row == tempCol)
                j++;
        }

        while (i <= n1 - 1 && a[i].row == tempRow)
            i++;
    }
    PRODUCT_SIZE = k;
    sparseProduct[0].value = k - 1;
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

    transposeSparseMatrix();
    printf("\n\nSparse Matrix 2 TRANSPOSE (Tuple form)");
    printSparseMatrix(transposeSparse2, SIZE2);

    calculateProduct(sparse1, transposeSparse2, SIZE1, SIZE2);
    printf("\n\nProduct of Sparse Matrices (Tuple form)");
    printSparseMatrix(sparseProduct, PRODUCT_SIZE);

    convertSparseToNormal();
    printf("\n\nProduct of matrices (Normal form)\n");
    printMatrix(matrixProduct, MATRIX_ROWS1, MATRIX_COLS2);

    //===========TO VERIFY RESULT============//
    // int k = 0, temp[100][100];
    // for (i = 0; i < MATRIX_ROWS1; i++)
    //     for (j = 0; j < MATRIX_COLS2; j++)
    //         for (k = 0; k < MATRIX_COLS1; k++)
    //             temp[i][j] += (matrix1[i][k] * matrix2[k][j]);
    // printf("\nPROdUCT ACTUAL (CALCULATED DIRECTLY) \n");
    // printMatrix(temp, MATRIX_ROWS1, MATRIX_COLS2);

    return 0;
}