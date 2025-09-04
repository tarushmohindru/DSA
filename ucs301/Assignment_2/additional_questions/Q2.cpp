#include <iostream>
#include <string>
using std::string;

int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        string s;
        std::cin >> s;
        int n = s.size();
        bool found = false;

        for (int i = 0; i < n - 2 && !found; i++)
        {
            for (int j = i + 1; j < n - 1 && !found; j++)
            {
                string A = s.substr(0, i + 1);
                string B = s.substr(i + 1, j - i);
                string C = s.substr(j + 1);

                auto isSub = [](const string &small, const string &big)
                {
                    return big.find(small) != string::npos;
                };

                if ((isSub(A, B) && isSub(A, C)) ||
                    (isSub(B, A) && isSub(B, C)) ||
                    (isSub(C, A) && isSub(C, B)))
                {
                    std::cout << "Yes\n";
                    found = true;
                }
            }
        }

        if (!found)
            std::cout << "No\n";
    }

    return 0;
}
