#include <iostream>
using namespace std;

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int count = 0;
    while (str[count] != '\0')
    {
        count++;
    }

    for (int i = 0; i < count / 2; i++)
    {
        char temp = str[i];
        str[i] = str[count - i - 1];
        str[count - i - 1] = temp;
    }

    cout << "Reversed string: " << str;
    return 0;
}