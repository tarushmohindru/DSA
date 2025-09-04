#include <iostream>
#include <vector>
using std::vector;

void duplicateZeros(vector<int> &arr)
{
    int n = arr.size();
    vector<int> result;

    for (int i = 0; i < n && (int)result.size() < n; i++)
    {
        result.push_back(arr[i]);
        if (arr[i] == 0 && (int)result.size() < n)
        {
            result.push_back(0);
        }
    }

        for (int i = 0; i < n; i++)
    {
        arr[i] = result[i];
    }
}

int main()
{
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    duplicateZeros(arr);

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    return 0;
}
