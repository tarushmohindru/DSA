#include <iostream>
using namespace std;

void printDiagonalMatrix(int arr[], int n)
{
    cout << "\nDiagonal Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << arr[i] << " ";
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

    int diagonalElements[n];
    cout << "Enter " << n << " diagonal elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> diagonalElements[i];
    }

    printDiagonalMatrix(diagonalElements, n);

    return 0;
}