#include <iostream>
#include <queue>
using std::queue;

class Stack
{
    queue<int> q1, q2;

public:
    void push(int x)
    {
        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        std::swap(q1, q2);
    }

    void pop()
    {
        if (q1.empty())
        {
            std::cout << "stack is empty" << '\n';
            return;
        }

        q1.pop();
    }

    int top()
    {
        if (q1.empty())
        {
            std::cout << "Stack is empty()" << '\n';
            return -1;
        }

        return q1.front();
    }

    bool isEmpty()
    {
        return q1.empty();
    }
};

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    std::cout << st.top() << '\n';
    st.pop();
    std::cout << st.top() << '\n';
    st.pop();
    std::cout << st.top() << '\n';

    return 0;
}