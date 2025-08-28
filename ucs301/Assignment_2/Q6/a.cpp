#include <iostream>
using namespace std;

int main()
{
    int A[100][3], T[100][3];
    int rows, cols, n;

    cout << "Enter rows, cols, non-zero elements: ";
    cin >> rows >> cols >> n;

    A[0][0] = rows;
    A[0][1] = cols;
    A[0][2] = n;

    cout << "Enter triplets (row col value):" << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }

    T[0][0] = A[0][1];
    T[0][1] = A[0][0];
    T[0][2] = A[0][2];

    int k = 1;
    for (int i = 0; i < cols; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (A[j][1] == i)
            {
                T[k][0] = A[j][1];
                T[k][1] = A[j][0];
                T[k][2] = A[j][2];
                k++;
            }
        }
    }

    cout << "\nTranspose (Triplet form):\n";
    for (int i = 0; i <= n; i++)
    {
        cout << T[i][0] << " " << T[i][1] << " " << T[i][2] << endl;
    }
    return 0;
}
