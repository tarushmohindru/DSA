#include <iostream>
#include <vector>
using std::vector;

class Stack
{
    int arr[1000];
    int top;

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
        if (!isFull())
            arr[++top] = x;
    }

    int pop()
    {
        if (isEmpty())
            return -1;
        return arr[top--];
    }

    int peek()
    {
        if (isEmpty())
            return -1;
        return arr[top];
    }
};

vector<int> prevSmaller(vector<int> &A)
{
    vector<int> result;
    Stack s;

    for (int i = 0; i < A.size(); i++)
    {
        while (!s.isEmpty() && s.peek() >= A[i])
        {
            s.pop();
        }

        if (s.isEmpty())
        {
            result.push_back(-1);
        }
        else
        {
            result.push_back(s.peek());
        }

        // Push current element
        s.push(A[i]);
    }

    return result;
}

int main()
{
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> ans = prevSmaller(A);

    std::cout << "Nearest smaller elements: ";
    for (int x : ans)
        std::cout << x << " ";
    std::cout << '\n';

    return 0;
}
