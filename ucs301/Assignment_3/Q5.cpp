#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
using std::string;

int evaluatePostfix(string &postfix)
{
    std::stack<int> s;

    for (char c : postfix)
    {
        if (isdigit(c))
        {
            s.push(c - '0');
        }
        else
        {
            int val2 = s.top();
            s.pop();
            int val1 = s.top();
            s.pop();

            switch (c)
            {
            case '+':
                s.push(val1 + val2);
                break;
            case '-':
                s.push(val1 - val2);
                break;
            case '*':
                s.push(val1 * val2);
                break;
            case '/':
                s.push(val1 / val2);
                break;
            case '^':
                s.push(pow(val1, val2));
                break;
            }
        }
    }

    return s.top();
}

int main()
{
    std::string postfix;
    std::cout << "Enter postfix expression: ";
    std::cin >> postfix;

    int result = evaluatePostfix(postfix);
    std::cout << "Result = " << result << '\n';

    return 0;
}
