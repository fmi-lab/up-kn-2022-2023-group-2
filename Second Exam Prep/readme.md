# Second Exam Preparation

## Task 01
Write a function that by given range of integers returns the starting position of the longest subsequence that is arithmetic progression. Make an example program showing that your function is correct.

### Example:
```
Input:                              Output:
0 2 4 5 2 3 -1 -5 -9 -6 -3 5        3 -1 -5 -9 -6 -3 5
```

## Task 02
You are given a number `N` followed by N floating point numbers, forming array. Your task is to find if there is number k (0 < k < N -1), such that all numbers in the array, that are k positions apart, have the same difference of m. If there is such number k - print it alongside m. If there are several k - print the highest. If there is not - print "No solution".

### Example:
```
Input:                  Output:
5                       3 2.1
1.6 2.3 3 3.7 4.4
```

## Task 03
You are given a number `N` followed by N letters and N digits. These letters and digits represent encoding - each letter corresponds to only one digit. After that you are given sentence of max 255 symbols. Some of the letters from the encoding may be present in the sentence, but there can also be other letters. For every word in the sentence decode the hidden letters and find the product of all the digits in the word. Finally output the sum of all products.

### Example:
```
Input:
6
a g l y b e
4 2 7 9 5 3
The bigger they are, the harder they fall.

Output:
340

Explanation:
The - 3, bigger - 60, they - 27, are - 12, harder - 12, fall - 196
```

## Task 04
You are given a number `N` between 0 and 255, followed by NxN matrix of integers. Write a function that traverses the matrix by its diagonals and stores every number, that contains two equal digits, in an array and returns its new logical end. Make an example program showing that your function is correct.

### Example:
```
Input:                  Output:
3 3                     868 2422 145172 301450
15 524 868
145172 6345 2422
945 301450 74952
```

## Task 05
You are given two positive integers N and M, followed by NxM matrix of integers. Your task is to replace every element of the matrix that has odd number of 1's in its binary notation with 0 and after that remove every row and every column that contains only 0's in such way that you move the rest of the rows and columns to fill the empty space.

### Example:
```
Input:              Output:
5 5                 3 5 0 
3 2 5 11 4          6 9 15
4 7 8 13 2          0 6 17
6 1 9 14 15
2 4 8 16 0
2 7 6 19 17
```