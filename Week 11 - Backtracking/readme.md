# Exercise 11 - Backtracking and More Recursion

## Task 01 - Quicksort
```c++
void quicksort(int* begin, int* end);
```

Write a function that sorts range using the `quick sort` algorithm.

### Example:
```c++
int arr[] {5, 2, 4, 6, 3, 9, 7, 1, 8};
quicksort(std::begin(arr), std::end(arr));
print(std::begin(arr), std::end(arr)); // -> 1 2 3 4 5 6 7 8 9
```

## Task 02 - Optimized Fibonacci
```c++
unsigned fib(unsigned n);
```

Write a function that finds the n-th Fibonacci number. In order to reduce the number of operations, use memoization.

### Example:
```c++
for (size_t i = 0; i < 100; i++)
{
    std::cout<<fib(i)<<' ';
}
/*
If your program lags, then your solution is incorrect
-> 0 1 1 2 3 5 8 13 21 34 55 89 ...
*/
```

## Task 03 - Flood Fill
```c++
void flood_fill(int canvas[][255], size_t height, size_t width, size_t x, size_t y, int color);
```

Write a function that accepts `canvas` (matrix of ints), its height and width, coordinates of starting point and a `color` (int). The function must `paint` all cells of the canvas, starting from the starting cell, that are `connected` to the starting cell, in the passed color. To `paint` means to change the value of that cell to the value of the `color` argument. Cell is `connected` to the starting cell if the value in that cell is the same as the value in the starting one and there is a path from the starting cell to that cell, that consists of cells, containing the same value as the starting cell.

### Example:
```c++
int canvas[][255]{
    {4, 2, 3, 2, 6},
    {5, 2, 2, 7, 10},
    {2, 2, 8, 2, 1},
    {9, 2, 2, 2, 3},
};

flood_fill(canvas, 4, 5, 1, 1, 20);
printMatrix(canvas, 4, 5);
/*
4   20   3    2    6
5   20   20   7    10
20  20   8    20   1
9   20   20   20   3
*/
```

## Task 04 - Number Game
```c++
bool winningSequence(int sequence[], size_t length);
```

Write a function that accepts ordered sequence of maximum 100 elements and finds if the following game can be won. The game is as follows: the game begins by removing one number from the sequence. Then there are 2 types of turns that can be made:
- remove another number that divides the previous
- remove another number that is divided by the previous.

The game can be won if there is such sequence of turns, so that at the end all of the numbers are removed.

### Bonus:
Print the winning sequence of turns.

### Example:
```c++
int sequence[]{42, 13, 17, 1, 3, 30, 10, 2, 6, 34, 2};
std::cout<<std::boolalpha<<winningSequence(sequence, 11); // -> true
```

## Task 05 - Crossword
```c++
unsigned crossword(char matrix[][255], size_t rows, size_t cols, char words[][255], size_t n);
```

Write a function that accepts matrix, representing crossword, a list of words and the size of the list and finds the number of words that are present in the crossword. A word is present in the crossword if each letter of the word is above, bellow, to the left or to the right of the previous letter.

### Example:
```c++
char matrix[][255] = {{'c', 'a', 't'},
                {'w', 'h', 'o'},
                {'w', 'i', 'n'}};
char words[][255] = {"cat", "hello", "what", "caca"};
std::cout << crossword(matrix, 3, 3, words, 4); // -> 2
```

### Explanation:
The words, present in the crossword, are "cat" and "what".

## Task 06* - Water Jugs
```c++
int water_jugs(unsigned first_max, unsigned second_max, unsigned target);
```

Write a function that solves the `Two Water Jugs` problem and returns the number of turns needed to be solved. The problem is as follows: you are given 2 empty water jugs with capacity `first_max` and `second_max`, where 0 < first_max < second_max. You have to use the jugs to measure `target` liters of water where target < second_max (in other words one of the jugs has to contain exactly `target` liters of water). The operations you can perform are:
- empty a jug
- fill a jug
- pour water from one jug to the other until one of the jugs is either empty or full 

### Example:
```c++
std::cout << water_jugs(4, 3, 2); // -> 4
```