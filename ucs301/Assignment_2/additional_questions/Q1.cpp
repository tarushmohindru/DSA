#include <iostream>

int countPairs(int arr[], int n, int k)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(arr[i] - arr[j]) == k)
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    int arr[n];

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    int k;
    std::cout << "Enter target: ";
    std::cin >> k;

    int result = countPairs(arr, n, k);

    std::cout << "Answer: " << result << '\n';

    return 0;
}