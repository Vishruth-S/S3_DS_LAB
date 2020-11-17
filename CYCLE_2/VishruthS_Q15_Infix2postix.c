//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 2 QUESTION 15
//To convert a given infix expression to postfix form

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//=======OPERATOR STACK=======//
char operatorStack[100];
int top = -1;

//=====OPERATOR STACK FUNCTIONS=====//
void OperatorStack_push(char ch)
{
    operatorStack[++top] = ch;
}

char OperatorStack_pop()
{
    return operatorStack[top--];
}

char OperatorStack_peek()
{
    return operatorStack[top];
}

bool OperatorStack_isEmpty()
{
    return top == -1;
}

//========OTHER FUNCTIONS========//

// To get precedence of current character
int getPrecedence(char c)
{
    switch (c)
    {
    case '$':
        return 4;
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return -1;
    }
}

// To check higher precedence of two characters
bool hasHigherPrecedence(char c1, char c2)
{
    return getPrecedence(c1) >= getPrecedence(c2);
}

// To check if current character is an Operand
bool isOperand(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
}

// To check if opening bracket
bool isOpeningBracket(char c)
{
    return c == '(' || c == '{' || c == '[';
}

// To check if closing bracket
bool isClosingBracket(char c)
{
    return c == ')' || c == '}' || c == ']';
}

//=======INFIX TO POSTFIX CONVERTER========//
void infix2postfix(char exp[])
{
    int n = strlen(exp);
    char postfix[100]; // POSTFIX ARRAY
    int k = 0;         // Index for postfix array
    for (int i = 0; i < n; i++)
    {
        if (isOperand(exp[i])) // If current character is operand
        {
            postfix[k++] = exp[i]; // Then push to postfix
        }
        else if (!isOpeningBracket(exp[i]) && !isClosingBracket(exp[i])) // If current character is operator (not brackets)
        {
            while (!OperatorStack_isEmpty() && !isOpeningBracket(OperatorStack_peek()) && hasHigherPrecedence(OperatorStack_peek(), exp[i])) // Checking precedence
            {
                postfix[k++] = OperatorStack_pop(); // If greater precedence, then pop and push top to postfix
            }
            OperatorStack_push(exp[i]); // If lower precedence, push to operator stack
        }
        else if (isOpeningBracket(exp[i])) // If opening bracket
        {
            OperatorStack_push(exp[i]); // Then push to operator stack
        }
        else if (isClosingBracket(exp[i])) // If closing bracket
        {
            while (!OperatorStack_isEmpty() && !isOpeningBracket(OperatorStack_peek())) // Till stack is empty and not opening bracket
            {
                postfix[k++] = OperatorStack_pop(); // pop operator stack and push to postfix
            }
            OperatorStack_pop(); // This is to pop the closing bracket
        }
    }
    while (!OperatorStack_isEmpty()) // For the remaining element in operator stack (if any)
    {
        postfix[k++] = OperatorStack_pop(); // Simply pop and push it to the postfix
    }
    printf("\nPostfix expression\n"); // Printing postfix expression
    for (int i = 0; i < k; i++)
    {
        printf("%c", postfix[i]);
    }
}

//=======MAIN FUNCTION=======//
int main()
{
    char exp[100]; // infix expression
    printf("\nEnter infix expression without any spaces");
    printf("\nFor unary - or +, use $. eg: a*-b must be entered as a*$b\n\n");
    scanf("%s", &exp);
    infix2postfix(exp);

    return 0;
}