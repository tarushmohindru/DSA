#include <iostream>

const int MAX = 10;
void multiplyMatrices(int a[][MAX], int b[][MAX], int c[][MAX], int r1, int c1, int r2, int c2)
{
    for (int i = 0; i < r1; ++i)
    {
        for (int j = 0; j < c2; ++j)
        {
            c[i][j] = 0;
            for (int k = 0; k < c1; ++k)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main()
{
    int r1, c1, r2, c2;
    std::cout << "Enter the size of first matrix: ";
    std::cin >> r1 >> c1;
    std::cout << "Enter the size of second matrix: ";
    std::cin >> r2 >> c2;

    if (c1 != r2)
    {
        std::cout << "Matrices cannot be multiplied." << std::endl;
        return 0;
    }

    int a[MAX][MAX];
    int b[MAX][MAX];

    std::cout << "Enter the elements of first matrix: " << '\n';
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            std::cin >> a[i][j];
        }
    }

    std::cout << "Enter the elements of second matrix: " << '\n';
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            std::cin >> b[i][j];
        }
    }

    int c[MAX][MAX];

    multiplyMatrices(a, b, c, r1, c1, r2, c2);

    std::cout << "Result of matrix multiplication:" << std::endl;
    for (int i = 0; i < r1; ++i)
    {
        for (int j = 0; j < c2; ++j)
        {
            std::cout << c[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}