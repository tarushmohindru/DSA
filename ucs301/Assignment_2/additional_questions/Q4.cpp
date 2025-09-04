#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

void sort(vector<int> &arr)
{

    std::sort(arr.begin(), arr.end());
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

    sort(arr);

    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    return 0;
}