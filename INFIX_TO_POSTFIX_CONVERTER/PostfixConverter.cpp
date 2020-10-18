// THIS IS A PROGRAM THAT TAKES AN INFIX EXPRESSION AND CONVERTS IT INTO POSTFIX EXPRESSION
// Done by - Vishruth S, https://vishruth-s.github.io/Me/

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

// Function to get precedence of character
int getPrecedence(char c)
{
    switch (c)
    {
    case '$':
        return 4;
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return -1;
    }
}

// Function to check if opening bracket
bool isOpeningBracket(char c)
{
    return c == '(' || c == '{' || c == '[';
}

// Function to check if closing bracket
bool isClosingBracket(char c)
{
    return c == ')' || c == '}' || c == ']';
}

int main()
{
    string s; //infix expression string
    cout << "\nRules for entering infix expression";
    cout << "\n1) Enter expression without any spaces";
    cout << "\n2) For unary - or +, use $. eg: a*-b must be entered as a*$b";
    cout << "\n\nEnter infix expression  ";
    getline(cin, s);

    stack<char> operators; //operator stack
    vector<char> postfix;  //postfix array

    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i])) //check if operand
        {
            postfix.push_back(s[i]);
        }
        else if (!isOpeningBracket(s[i]) && !isClosingBracket(s[i])) //if operator
        {
            while (!operators.empty() && !isOpeningBracket(operators.top()) && getPrecedence(s[i]) <= getPrecedence(operators.top()))
            {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.push(s[i]);
        }
        else if (isOpeningBracket(s[i])) //if opening parenthesis
        {
            operators.push(s[i]);
        }
        else if (isClosingBracket(s[i])) //if closing parenthesis
        {
            while (!operators.empty() && !isOpeningBracket(operators.top()))
            {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.pop();
        }
    }
    while (!operators.empty())
    {
        postfix.push_back(operators.top());
        operators.pop();
    }
    cout << "\nPostfix Expression: ";
    for (int i = 0; i < postfix.size(); i++)
    {
        cout << postfix[i];
    }
}
