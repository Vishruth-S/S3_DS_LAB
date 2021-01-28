//Program to find the factorial of a number without using recursive function

#include <stdio.h>

int fact (int n)
{
  int fac = 1;
  for (int i = n; i >= 1; i--)
    {
      fac *= i;
    }
  return fac;
}

int main ()
{
  int n, result;
  printf ("Enter the number whose factorial you want to find : ");
  scanf (" %d", &n);
  result = fact (n);
  printf("The factorial of the number without using recursive function is %d", result);
  return 0;
}

