/*Q10) Write a C program to enter two matrices in normal (conventional) form. 
Write a function to convert two matrices to tuple form and display it.  
Find the sum of the two matrices in tuple form and display the sum in tuple form
*/

#include <stdio.h>

struct term
{
    int row;
    int col;
    int value;
};

int i, j, m, n, c = 0, d = 0;
struct term a1[100], b1[100], c1[100];
int arr[100][100], arr1[100][100];

void convo()
{
    int k = 1;
    a1[0].row = m;
    a1[0].col = n;
    a1[0].value = c;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                a1[k].row = i;
                a1[k].col = j;
                a1[k].value = arr[i][j];
                k++;
            }
        }
    }

    printf("\nThe tuple form of entered first matrix is");
    for (i = 0; i <= c; i++)
    {
        printf("\n%d\t%d\t%d", a1[i].row, a1[i].col, a1[i].value);
    }
    k = 1;
    b1[0].row = m;
    b1[0].col = n;
    b1[0].value = d;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr1[i][j] != 0)
            {
                b1[k].row = i;
                b1[k].col = j;
                b1[k].value = arr1[i][j];
                k++;
            }
        }
    }

    printf("\nThe tuple form of entered second matrix is");
    for (i = 0; i <= d; i++)
    {
        printf("\n%d\t%d\t%d", b1[i].row, b1[i].col, b1[i].value);
    }
}

int main()
{
    int i, j, m1, n1, k = 1, v = 1, sum[100][100], ap, bp;
    printf("\nEnter the number of rows ");
    scanf("%d", &m);
    printf("\nEnter the number of coloumns ");
    scanf("%d", &n);
    printf("\nEnter the number of rows of 2nd matrix");
    scanf("%d", &m1);
    printf("\nEnter the number of coloumns of 2nd matrix ");
    scanf("%d", &n1);
    if (m1 == m && n1 == n)
    {

        printf("Enter the first matrix");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                scanf("%d", &arr[i][j]);
                if (arr[i][j] != 0)
                    c++;
            }
        }

        printf("\nThe matrix is\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("%d \t", arr[i][j]);
            }
            printf("\n");
        }

        printf("Enter the second matrix");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                scanf("%d", &arr1[i][j]);
                if (arr1[i][j] != 0)
                    d++;
            }
        }

        printf("\nThe matrix is\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("%d \t", arr1[i][j]);
            }
            printf("\n");
        }
        convo();
        c1[0].row = m;
        c1[0].col = n;
        ap = 1;
        bp = 1;
        while (ap <= c && bp <= c)
        {

            if (a1[ap].row < b1[bp].row)
            {

                c1[v].row = a1[ap].row;
                c1[v].col = a1[ap].col;
                c1[v].value = a1[ap].value;
                v++;
                ap++;
            }
            else if (a1[ap].row > b1[bp].row)
            {
                c1[v].row = b1[bp].row;
                c1[v].col = b1[bp].col;
                c1[v].value = b1[bp].value;
                v++;
                bp++;
            }
            else if (a1[ap].col < b1[bp].col)
            {
                c1[v].row = a1[ap].row;
                c1[v].col = a1[bp].col;
                c1[v].value = a1[ap].value;
                v++;
                ap++;
            }
            else if (a1[ap].col > b1[bp].col)
            {
                c1[v].row = b1[bp].row;
                c1[v].col = b1[bp].col;
                c1[v].value = b1[bp].value;
                v++;
                bp++;
            }
            else
            {
                c1[v].row = a1[ap].row;
                c1[v].col = a1[ap].col;
                c1[v].value = a1[ap].value + b1[bp].value;
                v++;
                ap++;
                bp++;
            }
        }
        if (ap <= c)
        {
            for (i = ap; i <= c; i++)
            {
                c1[v].row = a1[i].row;
                c1[v].col = a1[i].col;
                c1[v].value = a1[i].value;
                v++;
            }
        }
        else if (bp <= d)
        {
            for (i = bp; i <= d; i++)
            {
                c1[v].row = b1[i].row;
                c1[v].col = b1[i].col;
                c1[v].value = b1[i].value;
                v++;
            }
        }

        c1[0].value = v;
        printf("\n");
        printf("\nThe sum matrix in tuple form is: ");
        for (i = 0; i < v; i++)
        {

            printf("\n%d\t", c1[i].row);
            printf("%d\t", c1[i].col);
            printf("%d", c1[i].value);
        }

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                sum[i][j] = 0;
            }
        }
        for (i = 1; i < v; i++)
        {
            sum[c1[i].row][c1[i].col] = c1[i].value;
        }
        printf("\nThe Sum matrix is\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("%d \t", sum[i][j]);
            }
            printf("\n");
        }

        // ======TO VERIFY RESULT========//
        int temp[100][100];
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                temp[i][j] = arr[i][j] + arr1[i][j];

        printf("\nActual Sum matrix is\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("%d \t", temp[i][j]);
            }
            printf("\n");
        }
    }

    else
    {
        printf("The addition not possible");
    }
}
