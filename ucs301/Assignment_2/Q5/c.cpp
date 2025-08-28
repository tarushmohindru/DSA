#include <iostream>
using namespace std;

void printLowerTriangular(int arr[], int n)
{
    cout << "\nLower Triangular Matrix:\n";
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j <= i)
            {
                cout << arr[k] << " ";
                k++;
            }
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    int total = n * (n + 1) / 2;
    int lowerElements[total];

    cout << "Enter " << total << " elements : ";
    for (int i = 0; i < total; i++)
    {
        cin >> lowerElements[i];
    }

    printLowerTriangular(lowerElements, n);

    return 0;
}