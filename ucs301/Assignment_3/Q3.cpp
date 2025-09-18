#include <iostream>
#include <string>
using std::string;

class Stack
{
    char stack[100];
    int top;

public:
    Stack() { top = -1; }

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
        if (isFull())
            std::cout << "The stack is full" << '\n';
        else
            stack[++top] = x;
    }

    char pop()
    {
        if (isEmpty())
        {
            std::cout << "The stack is empty" << '\n';
            return '\0';
        }
        else
        {
            return stack[top--];
        }
    }

    char peek()
    {
        return stack[top];
    }
};

int main()
{
    string input;
    std::cout << "Enter string: ";
    std::cin >> input;

    Stack st = Stack();

    for (char c : input)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }

        if (c == ')')
        {
            if (st.pop() != '(')
            {
                std::cout << "Invalid parantheses" << '\n';
                exit(0);
            }
        }
        else if (c == '}')
        {
            if (st.pop() != '{')
            {
                std::cout << "Invalid parantheses" << '\n';
                exit(0);
            }
        }
        else if (c == ']')
        {
            if (st.pop() != '[')
            {
                std::cout << "Invalid parantheses" << '\n';
                exit(0);
            }
        }
    }

    std::cout << "valid parantheses" << '\n';

    return 0;
}