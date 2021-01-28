/*Q9) Write a C program to enter a matrix in normal (conventional) form. Write a function to convert 
the matrix to tuple form and display it. Also find the transpose of the matrix represented in tuple form 
and display the transpose in tuple form and normal form*/

#include<stdio.h>

struct term{
int row;
int col;
int value;
};



    int i,j,m,n;
   

    void conv(int m,int n,int c,int arr[100][100],struct term a1[100])
    {
        
        int k=1;
        a1[0].row=m;
        a1[0].col=n;
        a1[0].value=c;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(arr[i][j]!=0)
                {
                    a1[k].row=i;
                    a1[k].col=j;
                    a1[k].value=arr[i][j];
                    k++;
                }
            }
        }
    
        printf("\nThe tuple form of entered matrix is");
        for(i=0;i<c+1;i++)
        {
        
            printf("\n%d\t%d\t%d",a1[i].row,a1[i].col,a1[i].value);
        }

   
    }



    int main(){
    struct term a1[100],b1[100];
    int arr[100][100],c=0,b[100][100],k=1;
    printf("\nEnter the number of rows ");
    scanf("%d",&m);
    printf("\nEnter the number of coloumns ");
    scanf("%d",&n);
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]!=0)
                c++;
        }
    }
    printf("\nThe matrix is\n");
     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d \t",arr[i][j]);
            
        }
        printf("\n");
    }
    conv(m,n,c,arr,a1);

     for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
        b[i][j]=0;
        }
      
    }
    

   for(i=1;i<c+1;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                if(a1[i].col==j&&a1[i].row==k)
                b[j][k]=a1[i].value;
            }
        }
    }
     printf("\nThe transpose form of entered matrix is\n");  
       for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d \t",b[i][j]);
            
        }
        printf("\n");
    }   

    conv(n,m,c,b,b1);
    

}






