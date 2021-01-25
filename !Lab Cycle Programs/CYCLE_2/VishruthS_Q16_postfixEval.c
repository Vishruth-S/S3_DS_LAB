//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 2 QUESTION 16
//To evaluate a given postfix expression 

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// ===== RESULT STACK ======== //
int stack[100];
int top = -1;

// ===== STACK FUNCTIONS ===== //
void stack_push(int el)
{
    stack[++top] = el;
}

int stack_pop()
{
    return stack[top--];
}

int stack_peek()
{
    return stack[top];
}

// ====== OTHER FUNCTIONS ===== //

// To check if current character is digit
bool isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

// To perform the given operation on operands and return result
int performOperation(char operator, int op1, int op2)
{
    switch (operator)
    {
    case '+':
        return op2 + op1;
    case '-':
        return op2 - op1;
    case '*':
        return op2 * op1;
    case '/':
        return op2 / op1;
    case '^':
        return pow(op2, op1);
    default:
        return -1;
    }
}

// ===== POSTFIX EVALUATION FUNCTION ===== //
int postfixEval(char exp[])
{
    int n = strlen(exp);        // length of given expression
    for (int i = 0; i < n; i++) // for each character in expression
    {
        if (exp[i] == ' ')   // if character is space
            continue;        // then continue to next character
        if (isDigit(exp[i])) // if character is digit
        {
            int num = 0;
            while (isDigit(exp[i])) // To continue in case of multiple digits
            {
                num = num * 10 + (int)(exp[i] - '0'); // '0' is subtracted since exp[i] is a character
                i++;
            }
            i--;
            stack_push(num); // the resulting number is pushed to the stack
        }
        else // If operator
        {
            int op1 = stack_pop(); // Then pop two elements from stack
            int op2 = stack_pop();
            int result = performOperation(exp[i], op1, op2); // and perform the operation on them
            stack_push(result);                              // Push this result to the stack
        }
    }
    return stack_peek(); // The answer will be the top and only element remaining in stack
}

// ====== MAIN FUNCTION ==== //
int main()
{
    char exp[100]; // postfix expression
    printf("\nEnter postfix expression, each item must be space separated\n");
    printf("For example: 12 32 + 44 /\n");
    gets(exp);
    int EvaluatedValue = postfixEval(exp);
    printf("\nResult Of evaluated postfix:  %d", EvaluatedValue);

    return 0;
}