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

    for (int i = 0; i < rows; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < columns; j++)
        {
            rowSum += matrix[i][j];
        }
        std::cout << "Sum of Row " << i + 1 << ": " << rowSum << '\n';
    }

    for (int j = 0; j < columns; j++)
    {
        int colSum = 0;
        for (int i = 0; i < rows; i++)
        {
            colSum += matrix[i][j];
        }
        std::cout << "Sum of Column " << j + 1 << ": " << colSum << '\n';
    }

    return 0;
}