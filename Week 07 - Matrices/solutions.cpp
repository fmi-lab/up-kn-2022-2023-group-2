#include <iostream>

constexpr size_t MAX_SIZE = 255;

void print(const char matrix[][MAX_SIZE],
           size_t rows, size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void read(char matrix[][MAX_SIZE],
          size_t rows, size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

bool isValidPosition(int i, int j, int rows, int columns)
{
    return i >= 0 && i <= rows - 1 && j >= 0 && j <= columns - 1;
}

void pattern(const int arr[][MAX_SIZE], int rows, int columns)
{
    int i = 0, j = 0;
    while (i < rows - 1 || j < columns - 1)
    {
        int currentI = i, currentJ = j;
        std::cout << arr[i][j] << ' ';
        while (isValidPosition(i - 1, j + 1, rows, columns))
        {
            std::cout << arr[--i][++j] << ' ';
        }

        if (isValidPosition(currentI + 1, currentJ, rows, columns))
        {
            i = currentI + 1;
            j = currentJ;
        }
        else if (isValidPosition(currentI, currentJ + 1, rows, columns))
        {
            i = currentI;
            j = currentJ + 1;
        }
    }
    std::cout << arr[rows - 1][columns - 1];
}

int main()
{
    int matrix[][MAX_SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    pattern(matrix, 3, 3);

    return 0;
}