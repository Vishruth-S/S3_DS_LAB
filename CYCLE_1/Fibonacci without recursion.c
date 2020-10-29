//Write a C program to find the fibonacci series without using recursion

int main ()
{
 int n,n1=0,n2=1,n3;
 printf("How many members of the fibonacci series do you want to find : ");
 scanf("%d",&n);
 printf("\n%d , %d ",n1,n2);
 for(int i=0;i<n-2;i++)
 {
 n3=n1+n2;
 printf(", %d ",n3);
 n1=n2;
 n2=n3;
 }
 return 0;
}
