#include <iostream>
#include <string.h>
#include "Stack.h"

bool isOperator(char character)
{
    if (character == '+' || character == '-' || character == '*' || character == '/' || character == '^')
    {
        return true;
    }
    return false;
}

std::string convertToPostfix(std::string prefix)
{

    int length = prefix.size();
    Stack<std::string> *expression = new ArrayStack<std::string>(length);
    for (int i = length - 1; i >= 0; i--)
    {
        if (isOperator(prefix[i]))
        {

            std::string op1 = expression->top();
            expression->pop();
            std::string op2 = expression->top();
            expression->pop();
            std::string temp = op1 + op2 + prefix[i];

            expression->push(temp);
        }
        else
            expression->push(std::string(1, prefix[i]));
    }
    return expression->top();
}
int main()
{

    std::string prefix = "*-A/BC-/AKL";
    std::cout << "Prefix expression : " << prefix << std::endl;
    std::cout << "Postfix expression : " << convertToPostfix(prefix);
    // std::cout << isOperator('a') << std::endl;
}
