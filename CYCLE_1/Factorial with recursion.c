//Program to find factorial of a number using recursion

#include<stdio.h>
int fact(int n)
{
  if(n==0)
  return 1;
  else 
  return (n*fact(n-1));
}

int main()
{ 
    int num;
    float fac;
    printf("Enter the no");
    scanf("%d",&num);
    fac = fact(num);
    printf("The factorial of %d is %f",num,fac);
    return 0;

}