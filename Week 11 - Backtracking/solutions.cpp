#include <iostream>

void print(int *begin, int *end)
{
    while (begin != end)
    {
        std::cout << *begin << ' ';
        ++begin;
    }
}

void printMatrix(int matrix[][255], size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int *partition(int *begin, int *end, int pivot)
{
    while (begin != end)
    {
        if (*begin > pivot)
        {
            std::iter_swap(begin, end - 1);
            --end;
        }
        else
        {
            ++begin;
        }
    }

    return begin;
}

void quicksort(int *begin, int *end)
{
    if (begin != end)
    {
        int *mid = partition(begin, end, *begin);
        std::iter_swap(begin, mid - 1);
        quicksort(begin, mid - 1);
        quicksort(mid, end);
    }
}

unsigned memo_fib[100]{0, 1};
unsigned fib(unsigned n)
{
    if (n == 0 || memo_fib[n] != 0)
    {
        return memo_fib[n];
    }

    unsigned result = fib(n - 1) + fib(n - 2);
    memo_fib[n] = result;

    return result;
}

bool findWord(char matrix[][255], size_t rows, size_t cols, char *word, size_t x, size_t y, bool visited[][255])
{
    if (!*word)
    {
        return true;
    }

    if (x < 0 || y < 0 || x == rows || y == cols || *word != matrix[x][y] || visited[x][y])
    {
        return false;
    }

    visited[x][y] = true;

    if (findWord(matrix, rows, cols, word + 1, x + 1, y, visited))
    {
        return true;
    }
    if (findWord(matrix, rows, cols, word + 1, x - 1, y, visited))
    {
        return true;
    }
    if (findWord(matrix, rows, cols, word + 1, x, y + 1, visited))
    {
        return true;
    }
    if (findWord(matrix, rows, cols, word + 1, x, y - 1, visited))
    {
        return true;
    }

    visited[x][y] = false;

    return false;
}

unsigned crossword(char matrix[][255], size_t rows, size_t cols, char words[][255], size_t n)
{
    unsigned counter = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < rows; j++)
        {
            for (size_t k = 0; k < cols; k++)
            {
                bool visited[255][255]{};
                if (findWord(matrix, rows, cols, words[i], j, k, visited))
                {
                    ++counter;
                }
            }
        }
    }
    return counter;
}

void flood_fill(int canvas[][255], unsigned height, unsigned width, unsigned x, unsigned y, int color)
{
    int startingColor = canvas[x][y];
    canvas[x][y] = color;

    if (x != 0 && canvas[x - 1][y] == startingColor)
    {
        flood_fill(canvas, height, width, x - 1, y, color);
    }

    if (x != height - 1 && canvas[x + 1][y] == startingColor)
    {
        flood_fill(canvas, height, width, x + 1, y, color);
    }

    if (y != 0 && canvas[x][y - 1] == startingColor)
    {
        flood_fill(canvas, height, width, x, y - 1, color);
    }

    if (y != height - 1 && canvas[x][y + 1] == startingColor)
    {
        flood_fill(canvas, height, width, x, y + 1, color);
    }
}

bool isWinning(int sequence[], size_t length, int prev, size_t remaining, bool used[])
{
    if (remaining == 0)
    {
        return true;
    }

    for (size_t i = 0; i < length; i++)
    {
        if (!used[i] && (prev % sequence[i] == 0 || sequence[i] % prev == 0))
        {
            used[i] = true;

            if (isWinning(sequence, length, sequence[i], remaining - 1, used))
            {
                return true;
            }

            used[i] = false;
        }
    }

    return false;
}

bool winningSequence(int sequence[], size_t length)
{
    size_t i = 0;
    bool used[255]{1};
    while (i < length && !isWinning(sequence, length, sequence[i], length - 1, used))
    {
        used[i] = false;
        ++i;
        used[i] = true;
    }

    return i < length;
}

unsigned firstJug[255]{0};
unsigned secondJug[255]{0};
int iterator = 0;

bool pour(unsigned first_max, unsigned second_max, unsigned target, int first_current, int second_current, unsigned &counter)
{
    if (first_current < 0)
    {
        first_current = 0;
    }
    if (second_current < 0)
    {
        second_current = 0;
    }

    if (first_current > first_max)
    {
        first_current = first_max;
    }
    if (second_current > second_max)
    {
        second_current = second_max;
    }

    if (first_current == target || second_current == target)
    {
        return true;
    }

    for (int i = 0; i < iterator; i++)
    {
        if (firstJug[i] == first_current && secondJug[i] == second_current)
        {
            return false;
        }
    }
    firstJug[iterator] = first_current;
    secondJug[iterator] = second_current;
    iterator++;

    if (first_current == 0 && pour(first_max, second_max, target, first_max, second_current, counter))
    {
        counter++;
        return true;
    }
    if (first_current > 0 && second_current != second_max && pour(first_max, second_max, target, first_current - (second_max - second_current), second_current + first_current, counter))
    {
        counter++;
        return true;
    }
    if (second_current == second_max && pour(first_max, second_max, target, first_current, 0, counter))
    {
        counter++;
        return true;
    }

    return false;
}

int water_jugs(unsigned first_max, unsigned second_max, unsigned target)
{
    int first_current = 0;
    int second_current = 0;
    unsigned first_counter = 0;
    unsigned second_counter = 0;

    pour(first_max, second_max, target, first_current, second_current, first_counter);
    iterator = 0;
    pour(second_max, first_max, target, second_current, first_current, second_counter);

    return first_counter < second_counter ? first_counter : second_counter;
}

int main()
{
    char matrix[][255] = {{'c', 'a', 't'},
                          {'w', 'h', 'o'},
                          {'w', 'i', 'n'}};
    char words[][255] = {"cat", "hello", "what", "caca"};
    std::cout << crossword(matrix, 3, 3, words, 4); // -> 2
}