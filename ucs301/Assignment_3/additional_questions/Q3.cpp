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

vector<int> nextGreater(vector<int> &A)
{
    int n = A.size();
    vector<int> result(n, -1);
    Stack s;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.isEmpty() && s.peek() <= A[i])
        {
            s.pop();
        }

        if (!s.isEmpty())
        {
            result[i] = s.peek();
        }

        s.push(A[i]);
    }
    return result;
}

int main()
{
    vector<int> arr = {4, 5, 2, 25};
    vector<int> ans = nextGreater(arr);

    std::cout << "Next Greater Elements: ";
    for (int x : ans)
        std::cout << x << " ";
    std::cout << '\n';
    return 0;
}
