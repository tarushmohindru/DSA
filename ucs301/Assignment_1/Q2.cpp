#include <iostream>

void removeDuplicates(int arr[], int &size)
{
    if (size == 0 || size == 1)
    {
        std::cout << "Array has no duplicates to remove." << std::endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size;)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < size - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                size--;
            }
            else
            {
                j++;
            }
        }
    }
}

int main()
{
    int size = 0;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int arr[size];
    std::cout << "Enter the elements: " << '\n';
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }

    removeDuplicates(arr, size);

    std::cout << "Array after removing duplicates: " << '\n';
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    return 0;
}