#include <iostream>
#include <string>

int main()
{
    int T;
    std::cin >> T;

    while (T--)
    {
        std::string str1, str2;
        std::cin >> str1 >> str2;

        if (str1.size() != str2.size())
        {
            std::cout << "NO\n";
            continue;
        }

        int freq1[26] = {0};
        int freq2[26] = {0};

        for (char c : str1)
        {
            freq1[c - 'a']++;
        }
        for (char c : str2)
        {
            freq2[c - 'a']++;
        }

        bool isAnagram = true;
        for (int i = 0; i < 26; i++)
        {
            if (freq1[i] != freq2[i])
            {
                isAnagram = false;
                break;
            }
        }

        if (isAnagram)
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}
