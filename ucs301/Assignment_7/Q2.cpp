#include <iostream>
#include <vector>

void improvedSelectionSort(std::vector<int> &arr)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left < right)
    {
        int minIndex = left;
        int maxIndex = right;
        for (int i = left; i <= right; i++)
        {
            if (arr[i] < arr[minIndex])
            {
                minIndex = i;
            }
            if (arr[i] > arr[maxIndex])
            {
                maxIndex = i;
            }
        }
        std::swap(arr[left], arr[minIndex]);
        if (maxIndex == left)
        {
            maxIndex = minIndex;
        }
        std::swap(arr[right], arr[maxIndex]);
        left++;
        right--;
    }
}

int main()
{
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;
    std::vector<int> arr(n);
    std::cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    improvedSelectionSort(arr);
    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
    return 0;
}
