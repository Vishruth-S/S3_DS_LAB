/*Question11: Write a C program to enter two matrices in normal (conventional) form. Write a function to convert two matrices to tuple form and display it. Find the product of the two matrices in tuple form and display the product in tuple form*/

int MAX=100;

typedef struct{
			int row;
			int col;
			int value;
		}term;



#include<stdio.h>

int tuple(int a[10][10],int n,int m,term A[MAX])
{
	int i,j,k=0;
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	{	if(a[i][j]!=0)
		{	k++;//k stores number of non-zero values
			A[k].row=i+1;
			A[k].col=j+1;
			A[k].value=a[i][j];
		}
	}
	A[0].row=n;//First row first column is number of rows
	A[0].col=m;//First row second column is number of columns
	A[0].value=k;//First row third column is number of non-zero elements
	for(i=0;i<=k;i++)
		printf("%d %d %d \n",A[i].row,A[i].col,A[i].value);	
	return k;	
}	

void main()
{	term A[MAX],B[MAX],C[MAX];//C[MAX] will have product of matrices
	int i,j,a[10][10],n1,m1,n2,m2,c[10][10],b[10][10],k1,k2,k=0,p,found=0;
	printf("\nEnter details about first matrix-A");
	printf("\nEnter number of rows and columns  :: ");
	scanf("%d%d",&n1,&m1);//n1=number of rows of matrix-a,m1=number of columns of matrix-a
	printf("\nEnter elements in first matrix  :: ");
	for(i=0;i<n1;i++)
	for(j=0;j<m1;j++)
		scanf("%d",&a[i][j]);
	printf("Matrix-A\n");	
	for(i=0;i<n1;i++)
	{	for(j=0;j<m1;j++)
			printf("%d ",a[i][j]);	
		printf("\n");
	}		
	printf("\nEnter details about second matrix-B");
	printf("\nEnter number of rows and columns  :: ");
	scanf("%d%d",&n2,&m2);//n2=number of rows of matrix-b,m2=number of columns of matrix-b
	printf("\nEnter elements in second matrix  :: ");
	for(i=0;i<n2;i++)
	for(j=0;j<m2;j++)
		scanf("%d",&b[i][j]);	
	printf("Matrix-B\n");
	for(i=0;i<n2;i++)
	{	for(j=0;j<m2;j++)
			printf("%d ",b[i][j]);	 
		printf("\n");
	}
	printf("\nMatrix-A in tuple form\n");	
	k1=tuple(a,n1,m1,A);
	printf("\nMatrix-B in tuple form\n");	
	k2=tuple(b,n2,m2,B);
	if(A[0].col==B[0].row)
	{
		for(i=1;i<=k1;i++)
		for(j=1;j<=k2;j++)
		{	if(A[i].col==B[j].row)
			{	for(p=1;p<=k;p++)
				if(C[p].row==A[i].row&&C[p].col==B[j].col)
				{	C[p].value=C[p].value+A[i].value*B[j].value;
					found=1;
					continue;
				}	
				if(found==0)		
				{	k++;
				C[k].value=C[k].value+A[i].value*B[j].value;
				C[k].row=A[i].row;
				C[k].col=B[j].col;
				}
				found=0;	
			}	
		}
		C[0].row=n1;//First row first column is number of rows
		C[0].col=m2;//First row second column is number of columns
		C[0].value=k;//First row third column is number of non-zero elements
		printf("\nThe Product:\n");	
		for(i=0;i<=k;i++)
		printf("%d %d %d \n",C[i].row,C[i].col,C[i].value);
	}
	else
		printf("\nProduct can't be found\n");	
}				
	
	
	
	
				
				
