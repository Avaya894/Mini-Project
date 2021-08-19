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
    Stack *expression = new ArrayStack(length);
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
    std::cout << "****************************" << std::endl;
    std::string postfix = "";
    while (!(expression->isEmpty()))
    {
        postfix += expression->pop();
        std::cout << "Postfix now:" << postfix << std::endl;
    }
    return postfix;
}
int main()
{
    std::string prefix = "- - * a b * / c + d * e f g h";
    // std::cout << "Enter the prefix:" << std::endl;
    // std::cin >> prefix ;
    std::cout << "Prefix expression : " << prefix << std::endl;
    std::cout << "Postfix expression : " << convertToPostfix(prefix);
    // std::cout << isOperator('a') << std::endl;
}
