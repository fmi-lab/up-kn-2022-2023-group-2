# Exercise 07 - Matrices

```c++
constexpr size_t MAX_SIZE = 255;
```

## Task 01 - Print Matrix
```c++
void print(const int arr[][MAX_SIZE], size_t rows, size_t columns);
```

Write a function that prints the elements of a matrix.

### Example:
```c++
int matrix[][MAX_SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

print(matrix, 3, 3); /* -> 1 2 3
                           4 5 6
                           7 8 9 */
```

## Task 02 - Min Elements
```c++
size_t minElements(const int arr[][MAX_SIZE], size_t rows, size_t columns, int output[]);
```

Writa a function that copies the smallest elements on every row of a matrix into `output` array and returns the size of that array.

### Example:
```c++
int arr[][MAX_SIZE]{
    {1, 2},
    {3, 2},
    {5, 3}
};
int output[MAX_SIZE]{};
size_t size = minElements(arr, 3, 2, output);

for(size_t i = 0; i < size; i++) {
    std::cout<<output[i]<<' ';
}

// -> 1 2 3
```

## Task 03 - Main Diagonal
```c++
void mainDiagonal(const int arr[][MAX_SIZE], size_t n);
```

Write a function that prints the main diagonal of a NxN matrix.

### Bonus:
Do the same for the secondary diagonal.

### Example:
```c++
int matrix[][MAX_SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

mainDiagonal(matrix, 3); // -> 1 5 9
```

## Task 04 - Triangular Matrix
```c++
bool isTriangular(const int arr[][MAX_SIZE], size_t n);
```

Write a function that checks if a NxN matrix is triangular (has 0 in every cell bellow the main diagonal).

### Example:
```c++
int matrix[][MAX_SIZE] = {
        {1, 2, 3},
        {0, 5, 6},
        {0, 0, 9}
    };

std::cout << std::boolalpha << isTriangular(matrix, 3); // -> true
```

## Task 05 - Transpose Matrix
```c++
void transpose(const int arr[][MAX_SIZE], size_t rows, size_t columns, int destination[][MAX_SIZE]);
```

Write a function that by a given matrix copies the transposed matrix into `destination` matrix.

### Example:
```c++
int arr[][MAX_SIZE]{
    {1, 2},
    {3, 4},
    {5, 6}
};

int output[MAX_SIZE][MAX_SIZE]{};
transpose(arr, 3, 2, output);
print(output, 2, 3); /* -> 1 3 5
                           2 4 6 */
```

## Task 06 - Multiply Matrices
```c++
void multiply(const int lhs[][MAX_SIZE], unsigned lhs_rows, unsigned lhs_columns, const int rhs[][MAX_SIZE], int destination[][MAX_SIZE]);
```

Write a function that multiplies two matrices and copies the result in `destination` matrix.

### Example:
```c++
int first[][MAX_SIZE]{
    {1, 2, 3},
    {4, 5, 6},
};

int second[][MAX_SIZE]{
    {7, 8},
    {9, 10},
    {11, 12}
};

int output[MAX_SIZE][MAX_SIZE]{};

multiply(first, 2, 3, second, output);

print(output, 2, 2); /* -> 58 64
                           139 154 */
```

## Task 07 - Traversal Pattern
```c++
void pattern(const int arr[][MAX_SIZE], size_t rows, size_t columns);
```

Write a function that traverses a matrix, following this pattern.

![Image](./matrix.png)

### Example:
```c++
int matrix[][MAX_SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

pattern(matrix, 3, 3); // -> 1 4 2 7 5 3 8 6 9
```

## Task 08** - Magic Square
```c++
void magicSquare(size_t n, int destination[][MAX_SIZE]);
```

Write a function that generates magic square (the sum of all elements on each row, column and diagonal is the same) and copies it into `destination` matrix.

### Tip:
There are 3 different ways of generating magic square based on the number of rows.

### Example:
```c++
int arr[255][255];
magicSquare(4);
print(arr, 4, 4);
/* -> 16 2 3 13 
      5 11 10 8 
      9  7 6 12 
      4 14 15 1 */
```