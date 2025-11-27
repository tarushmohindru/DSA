#include <iostream>
#include <queue>

class Stack
{
    std::queue<int> q;

public:
    void push(int value)
    {
        q.push(value);
        int sz = q.size();
        for (int i = 0; i < sz - 1; ++i)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        if (q.empty())
        {
            std::cout << "Stack is empty." << '\n';
            return;
        }
        std::cout << q.front() << " popped." << '\n';
        q.pop();
    }

    void top()
    {
        if (q.empty())
        {
            std::cout << "Stack is empty." << '\n';
        }
        else
        {
            std::cout << "Top element: " << q.front() << '\n';
        }
    }

    void display()
    {
        if (q.empty())
        {
            std::cout << "Stack is empty." << '\n';
            return;
        }
        std::queue<int> copy = q;
        std::cout << "Stack elements (top to bottom): ";
        while (!copy.empty())
        {
            std::cout << copy.front() << " ";
            copy.pop();
        }
        std::cout << '\n';
    }
};

int main()
{
    Stack stack;
    int choice = 0;
    do
    {
        std::cout << "\n-- Stack Using One Queue --" << '\n';
        std::cout << "1. Push" << '\n';
        std::cout << "2. Pop" << '\n';
        std::cout << "3. Top" << '\n';
        std::cout << "4. Display" << '\n';
        std::cout << "5. Exit" << '\n';
        std::cout << "Enter your choice: ";

        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int value;
            std::cout << "Enter value to push: ";
            std::cin >> value;
            stack.push(value);
            break;
        }
        case 2:
            stack.pop();
            break;
        case 3:
            stack.top();
            break;
        case 4:
            stack.display();
            break;
        case 5:
            std::cout << "Exiting." << '\n';
            break;
        default:
            std::cout << "Invalid choice, try again." << '\n';
        }
    } while (choice != 5);

    return 0;
}
