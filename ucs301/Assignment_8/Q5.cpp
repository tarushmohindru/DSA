#include <iostream>
#include <vector>

void heapifyMax(std::vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void heapifyMin(std::vector<int> &arr, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
    {
        smallest = left;
    }
    if (right < n && arr[right] < arr[smallest])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        std::swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void heapSortIncreasing(std::vector<int> arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyMax(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapifyMax(arr, i, 0);
    }
    std::cout << "Sorted in increasing order: ";
    for (int value : arr)
    {
        std::cout << value << " ";
    }
    std::cout << '\n';
}

void heapSortDecreasing(std::vector<int> arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyMin(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapifyMin(arr, i, 0);
    }
    std::cout << "Sorted in decreasing order: ";
    for (int value : arr)
    {
        std::cout << value << " ";
    }
    std::cout << '\n';
}

int main()
{
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;
    std::vector<int> arr(n);
    std::cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    int choice;
    std::cout << "1. Increase order" << '\n';
    std::cout << "2. Decrease order" << '\n';
    std::cout << "Enter choice: ";
    std::cin >> choice;

    if (choice == 1)
    {
        heapSortIncreasing(arr);
    }
    else if (choice == 2)
    {
        heapSortDecreasing(arr);
    }
    else
    {
        std::cout << "Invalid choice." << '\n';
    }
    return 0;
}
