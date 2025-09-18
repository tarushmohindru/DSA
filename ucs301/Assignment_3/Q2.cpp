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
    string str = "DataStructure";
    Stack s;

    for (char c : str)
    {
        s.push(c);
    }

    string reversed = "";
    while (!s.isEmpty())
    {
        reversed += s.pop();
    }

    std::cout << "Original: " << str << '\n';
    std::cout << "Reversed: " << reversed << '\n';

    return 0;
}