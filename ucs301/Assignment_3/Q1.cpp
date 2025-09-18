#include <iostream>

class Stack
{
    int stack[100];
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

    void push(int x)
    {
        if (isFull())
        {
            std::cout << "The stack is full" << '\n';
        }
        else
        {
            stack[++top] = x;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            std::cout << "The stack is empty" << '\n';
        }
        else
        {
            std::cout << "Removed " << stack[top--] << " from the stack" << '\n';
        }
    }

    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            std::cout << stack[i] << " ";
        }
        std::cout << '\n';
    }

    int peek()
    {
        return stack[top];
    }
};

int main()
{
    Stack st = Stack();
    while (true)
    {
        int choice;

        std::cout << "1. Push" << '\n';
        std::cout << "2. Pop" << '\n';
        std::cout << "3. is Empty?" << '\n';
        std::cout << "4. is Full?" << '\n';
        std::cout << "5. Display stack" << '\n';
        std::cout << "6. Peek" << '\n';
        std::cout << "7. Quit" << '\n';
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            int x;
            std::cout << "Enter value to push: ";
            std::cin >> x;
            st.push(x);
            std::cout << "Value pushed to the stack" << '\n';
            break;

        case 2:
            st.pop();
            break;

        case 3:
            if (st.isEmpty())
            {
                std::cout << "True" << '\n';
            }
            else
            {
                std::cout << "False" << '\n';
            }
            break;

        case 4:
            if (st.isFull())
            {
                std::cout << "True" << '\n';
            }
            else
            {
                std::cout << "False" << '\n';
            }
            break;

        case 5:
            st.display();
            break;

        case 6:
            std::cout << st.peek() << '\n';
            break;

        default:
            exit(0);
        }
    }

    return 0;
}