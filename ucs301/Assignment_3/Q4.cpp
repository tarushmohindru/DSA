#include <iostream>
#include <string>
#include <cctype>
using std::string;

class Stack
{
    char stack[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top < 0;
    }
    bool isFull()
    {
        return top >= 99;
    }

    void push(char x)
    {
        if (!isFull())
            stack[++top] = x;
    }

    char pop()
    {
        if (isEmpty())
            return '\0';
        return stack[top--];
    }

    char peek()
    {
        if (isEmpty())
            return '\0';
        return stack[top];
    }
};

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

string infixToPostfix(string &infix)
{
    Stack s;
    string postfix = "";

    for (char c : infix)
    {
        if (isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix += s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c))
            {
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty())
    {
        postfix += s.pop();
    }

    return postfix;
}

int main()
{
    std::string infix;
    std::cout << "Enter infix expression: ";
    std::cin >> infix;

    std::string postfix = infixToPostfix(infix);
    std::cout << "Postfix expression: " << postfix << '\n';

    return 0;
}
