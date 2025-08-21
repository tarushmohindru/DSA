#include <iostream>

void reverseArray(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    int size = 0;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }

    reverseArray(arr, size);

    std::cout << "Reversed Array: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    return 0;
}