// Program to check for valid parenthesis in a given expression

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Stack and its functions
char stk[80];
const int MAX = 80;
int top = -1;
void stkPush(char);
void stkPop();
char stkTop();
bool stkEmpty();

// Check valid or not
bool isValidParenthesis(char *s)
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '<')
            stkPush(s[i]);
        else if (s[i] == ')' || s[i] == ']' || s[i] == '>')
        {
            if ((s[i] == ')' && (stkEmpty() || stkTop() != '(')) 
             || (s[i] == ']' && (stkEmpty() || stkTop() != '[')) 
             || (s[i] == '>' && (stkEmpty() || stkTop() != '<')))
                return false;
            stkPop();
        }
    }
    return stkEmpty();
}

int main()
{
    char exp[80];
    printf("\nEnter expression without spaces\n");
    scanf("%s", exp);
    if (isValidParenthesis(exp))
        printf("\nValid");
    else
        printf("\nNope");
}

void stkPush(char c)
{
    if (top == MAX - 1)
        return;
    stk[++top] = c;
}

void stkPop()
{
    if (top == -1)
        return;
    top--;
}

char stkTop()
{
    if (top == -1)
        return '0';
    return stk[top];
}

bool stkEmpty()
{
    return top == -1;
}