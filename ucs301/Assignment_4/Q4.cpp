#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
using std::queue, std::unordered_map, std::string;

void firstNonRepeating(string str)
{
    queue<char> q;
    unordered_map<char, int> freq;

    for (char c : str)
    {
        if (c == ' ')
            continue;

        freq[c]++;
        q.push(c);

        while (!q.empty() && freq[q.front()] > 1)
        {
            q.pop();
        }

        if (q.empty())
        {
            std::cout << "-1 ";
        }
        else
        {
            std::cout << q.front() << " ";
        }
    }

    std::cout << '\n';
}

int main()
{
    string input;
    std::cout << "Enter string: ";
    std::getline(std::cin, input);

    firstNonRepeating(input);

    return 0;
}