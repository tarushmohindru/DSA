#include <iostream>

class Stack
{
    int arr[1000];
    int top;
    int minElement;

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == 999;
    }

    void push(int x)
    {
        if (isFull())
        {
            std::cout << "Stack Overflow" << "\n";
            return;
        }

        if (isEmpty())
        {
            top++;
            arr[top] = x;
            minElement = x;
        }
        else if (x >= minElement)
        {
            arr[++top] = x;
        }
        else
        {
            arr[++top] = 2 * x - minElement;
            minElement = x;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack Underflow\n";
            return -1;
        }

        int t = arr[top--];

        if (t >= minElement)
        {
            return t;
        }
        else
        {
            int realVal = minElement;
            minElement = 2 * minElement - t;
            return realVal;
        }
    }

    int peek()
    {
        if (isEmpty())
            return -1;
        int t = arr[top];
        if (t >= minElement)
            return t;
        else
            return minElement;
    }

    int getMin()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty" << "\n";
            return -1;
        }
        return minElement;
    }
};

int main()
{
    Stack s;
    s.push(3);
    s.push(5);
    std::cout << s.getMin() << "\n";
    s.push(2);
    s.push(1);
    std::cout << s.getMin() << "\n";
    std::cout << s.pop() << "\n";
    std::cout << s.getMin() << "\n";
    std::cout << s.pop() << "\n";
    std::cout << s.getMin() << "\n";
}
