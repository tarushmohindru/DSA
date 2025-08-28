#include <iostream>
using namespace std;

int main()
{
    int A[100][3], B[100][3], C[100][3];
    int n1, n2;

    cout << "Enter rows, cols, non-zero elements for A: ";
    cin >> A[0][0] >> A[0][1] >> A[0][2];
    n1 = A[0][2];
    cout << "Enter triplets for A:\n";
    for (int i = 1; i <= n1; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    cout << "Enter rows, cols, non-zero elements for B: ";
    cin >> B[0][0] >> B[0][1] >> B[0][2];
    n2 = B[0][2];
    cout << "Enter triplets for B:\n";
    for (int i = 1; i <= n2; i++)
        cin >> B[i][0] >> B[i][1] >> B[i][2];

    if (A[0][1] != B[0][0])
    {
        cout << "Multiplication not possible (dimension mismatch)\n";
        return 0;
    }

    int rows = A[0][0], cols = B[0][1];
    int temp[50][50] = {0}; // intermediate normal form

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (A[i][1] == B[j][0])
            {
                temp[A[i][0]][B[j][1]] += A[i][2] * B[j][2];
            }
        }
    }

    C[0][0] = rows;
    C[0][1] = cols;
    int k = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (temp[i][j] != 0)
            {
                C[k][0] = i;
                C[k][1] = j;
                C[k][2] = temp[i][j];
                k++;
            }
        }
    }
    C[0][2] = k - 1;

    cout << "\nMultiplication Result (Triplet form):\n";
    for (int p = 0; p <= C[0][2]; p++)
    {
        cout << C[p][0] << " " << C[p][1] << " " << C[p][2] << endl;
    }
    return 0;
}
