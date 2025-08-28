#include <iostream>
#include <string>
using namespace std;

void concatenate(string str1, string str2)
{
    string str3 = str1 + " " + str2;
    cout << "str3: " << str3 << endl;
}

int main()
{
    string str1 = "hello";
    string str2 = "guyzz!";

    concatenate(str1, str2);
}