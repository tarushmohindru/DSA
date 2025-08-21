#include <iostream>

int main()
{
    int rows, columns;
    std::cout << "Enter the number of rows and columns: ";
    std::cin >> rows >> columns;

    int matrix[rows][columns];

    std::cout << "Enter the elements of the matrix: " << '\n';
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    int transpose[columns][rows];

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    std::cout << "Transpose of the Matrix:" << '\n';
    for (int i = 0; i < columns; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            std::cout << transpose[i][j] << " ";
        }
        std::cout << '\n';
    }

    return 0;
}