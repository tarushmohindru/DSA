#include <iostream>
using namespace std;

int getLength(string s)
{
    int count = 0;
    while (s[count] != '\0')
    {
        count++;
    }
    return count;
}

string toLowerCase(string s)
{
    int n = getLength(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] + 32;
        }
    }
    return s;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    str = toLowerCase(str);

    cout << "String in lowercase: " << str;
    return 0;
}