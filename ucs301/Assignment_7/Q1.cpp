#include <iostream>
#include <vector>

void printArray(const std::vector<int> &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

void selectionSort(std::vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
    std::cout << "Selection Sort: ";
    printArray(arr);
}

void insertionSort(std::vector<int> arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    std::cout << "Insertion Sort: ";
    printArray(arr);
}

void bubbleSort(std::vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
    std::cout << "Bubble Sort: ";
    printArray(arr);
}

void merge(std::vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1);
    std::vector<int> R(n2);
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }
    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

void mergeSortHelper(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSort(std::vector<int> arr)
{
    mergeSortHelper(arr, 0, arr.size() - 1);
    std::cout << "Merge Sort: ";
    printArray(arr);
}

int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortHelper(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(std::vector<int> arr)
{
    quickSortHelper(arr, 0, arr.size() - 1);
    std::cout << "Quick Sort: ";
    printArray(arr);
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
    selectionSort(arr);
    insertionSort(arr);
    bubbleSort(arr);
    mergeSort(arr);
    quickSort(arr);
    return 0;
}
