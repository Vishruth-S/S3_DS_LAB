//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 2 QUESTION 17
//To evaluate a given prefix expression 

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// ======= RESULT STACK ======== //
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
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '^':
        return pow(op1, op2);
    default:
        return -1;
    }
}

// ======== PREFIX EVALUATION ========//
int prefixEval(char exp[])
{
    int n = strlen(exp);
    for (int i = n - 1; i >= 0; i--) // Iterate from right to left
    {
        if (exp[i] == ' ')   // If empty space
            continue;        //  the continue to next character
        if (isDigit(exp[i])) // If number
        {
            int num = 0, k = 1;
            while (isDigit(exp[i])) // For multi-digit numbers, keep reading until end of number
            {
                num = num + (int)(exp[i] - '0') * k; // Logic for generating number from digits
                k *= 10;
                i--;
            }
            i++;
            stack_push(num); // Push this num to result stack
        }
        else // If operator
        {
            int op1 = stack_pop(); // Pop two elements from stack
            int op2 = stack_pop();
            int res = performOperation(exp[i], op1, op2); // And perform the operation on them
            stack_push(res);                              // Push this to the result stack
        }
    }
    return stack_peek(); // The answer will be the top and only element remaining in stack
}

// ===== MAIN FUNCTION ====== //
int main()
{
    char exp[100];
    printf("\nEnter prefix expression, each item must be space separated\n");
    printf("For example: - + 8 / 6 3 12\n");
    gets(exp);
    int eval = prefixEval(exp);
    printf("\nEvaluated prefix: %d", eval);

    return 0;
}