#include <iostream>
using namespace std;
int main()
{

    int n;
    cout << "enter number of elements in array: " << endl;
    cin >> n;

    int arr[n];

    cout << "enter elemnts in array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int temp;
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n - j - 1; k++)
        {
            if (arr[k] > arr[k + 1])
            {
                temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }

    int count = 1;
    for (int x = 0; x < n; x++)
    {
        if (arr[x - 1] != arr[x])
        {
            count++;
        }
    }

    cout << "number of distinct elements= " << count;
    return 0;
}