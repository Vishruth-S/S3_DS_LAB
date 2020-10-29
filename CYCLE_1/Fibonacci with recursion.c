//Write a C program to find the fibonacci series using recursion

#include<stdio.h>
int f(int);
int main()
{
 int n, i = 0, c;
 printf("Enter the number of terms of fibonacci series you want to find : ");
 scanf("%d", &n);
 for (c = 1; c <= n; c++)
 {
 printf("%d\t", f(i));
 i++;
 }
 return 0;
}
int f(int n)
{
 if (n == 0 || n == 1)
 return n;
 else
 return (f(n-1) + f(n-2));
}

