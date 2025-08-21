#include <iostream>

void createArray(int arr[], int size)
{
    std::cout << "Enter the elements: " << '\n';
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
    std::cout << "Array created succesfully." << '\n';
}

void displayArray(int arr[], int size)
{
    std::cout << "[ ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i != size - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << " ]" << '\n';
}

void insert(int arr[], int size)
{
    if (size >= 100)
    {
        std::cout << "Array is full. Cannot insert.\n";
        return;
    }
    int ele, idx;
    std::cout << "Enter the element to insert: ";
    std::cin >> ele;
    std::cout << "Enter the index: ";
    std::cin >> idx;

    if (idx < 1 || idx > size + 1)
    {
        std::cout << "Invalid position.\n";
        return;
    }

    int temp = arr[idx];
    arr[idx] = ele;

    for (int i = idx + 1; i < size + 1; i++)
    {
        int t = arr[i];
        arr[i] = temp;
        temp = t;
    }
    std::cout << "Element inserted." << '\n';
}

void deleteElement(int arr[], int size)
{
    if (size == 0)
    {
        std::cout << "Array is empty. Cannot delete.\n";
        return;
    }
    int idx;
    std::cout << "Enter the index to delete: ";
    std::cin >> idx;

    if (idx < 0 || idx > size - 1)
    {
        std::cout << "Invalid position.\n";
        return;
    }

    for (int i = idx; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }

    std::cout << "Element deleted successfully." << '\n';
}

void linearSearch(int arr[], int size)
{
    if (size == 0)
    {
        std::cout << "Array is empty. Cannot search." << '\n';
        return;
    }
    int ele;
    std::cout << "Enter the element to search: ";
    std::cin >> ele;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == ele)
        {
            std::cout << "Element found at index " << i << "." << '\n';
            return;
        }
    }
    std::cout << "Element not found in the array." << '\n';
}

int main()
{
    int arr[100];
    int size = 0;
    int choice = 0;

    do
    {
        std::cout << "--Menu--" << '\n';
        std::cout << "1. Create" << '\n';
        std::cout << "2. Display" << '\n';
        std::cout << "3. Insert" << '\n';
        std::cout << "4. Delete" << '\n';
        std::cout << "5. Linear search" << '\n';
        std::cout << "6. Exit" << '\n';

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter the size of the array: ";
            std::cin >> size;
            createArray(arr, size);
            break;

        case 2:
            displayArray(arr, size);
            break;

        case 3:
            insert(arr, size);
            size++;
            break;

        case 4:
            deleteElement(arr, size);
            size--;
            break;

        case 5:
            linearSearch(arr, size);
            break;

        default:
            break;
        }
    } while (choice != 6);

    return 0;
}