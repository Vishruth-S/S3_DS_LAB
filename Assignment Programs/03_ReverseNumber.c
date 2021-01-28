//  program to enter an integer and to reverse the digits of the integer using suitable data structure

#include <stdio.h>

// Time complexity O(d), space complexity: O(d), where d is number of digits
int reverseNumber(int n)
{
    int stack[100], top = -1;
    while (n)
    {
        stack[++top] = (n % 10);
        n /= 10;
    }
    int rev = 0, i = 1;
    while (top >= 0)
    {
        rev = (stack[top--] * i) + rev;
        i *= 10;
    }
    return rev;
}

int main()
{
    int n;
    printf("\nEnter a number: ");
    scanf("%d", &n);
    int rev = reverseNumber(n);
    printf("\nReversed number: %d", rev);
    return 0;
}