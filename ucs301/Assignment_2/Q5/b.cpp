#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    int a[n];     // Main diagonal
    int b[n - 1]; // Super diagonal
    int c[n - 1]; // Sub diagonal

    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            if (i == j)
                a[i] = temp;
            else if (i == j + 1)
                c[j] = temp;
            else if (i + 1 == j)
                b[i] = temp;
        }
    }

    cout << "Matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << a[i] << " ";
            else if (i == j + 1)
                cout << c[j] << " ";
            else if (i + 1 == j)
                cout << b[i] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
}
