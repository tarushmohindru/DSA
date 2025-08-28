#include <iostream>
using namespace std;

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter target: ");
    scanf("%d", &target);

    // Binary Search
    int left = 0;
    int right = n;

    bool found;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
        {
            printf("Element found at index %d\n", mid);
            found = 1;
            break;
        }
        else if (target < arr[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    if (!found)
    {
        printf("Element not found!\n");
    }

    return 0;
}