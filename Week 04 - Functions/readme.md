# Exercise 04 - Functions

## Instructions:

Write every task in a separate function. Before you begin solving each of the tasks, think about which of the logic you can separate in functions. If later on you encounter the same problem as before, then probably you can write a function to solve that problem. Don't worry to create functions even for smaller problems if those problems are recurring. The task for today is to learn to identify functions while reading the task.

## Task 01 - Average

You are given a stream of numbers untill you receive `0`. Write a function that finds the current average after every number.

### Example:
| Input | Output |
| :-----: | :------: |
| 5 2 17 6 9 0 | 5 3.5 8 7.5 7.8 |
| 15 24 16 5 0 2 7 | 15 19.5 18.3333 15 |

## Task 02 - Cubes

You are given a positive integer `n`. Write a function that prints all numbers that are less than `n` and are cubes.

### Example:
| Input | Output |
| :-----: | :------: |
| 900 | 1 8 27 64 125 216 343 512 729 |

## Task 03 - Sequence

You are given a positive integer `n`. Write a function that prints the first `n` members of the sequence:

<pre>
a<sub>i</sub> = 2*i<sup>3</sup> + 3*i
</pre>

### Example:
| Input | Output |
| :-----: | :------: |
| 6 | 5 22 63 140 265 450 |

## Task 04 - Prime numbers

You are given a positive integer `n`. Write a function that prints the first `n` prime numbers.

### Example:
| Input | Output |
| :-----: | :------: |
| 5 | 2 3 5 7 11 |

## Task 05 - Combinations

You are given two positive integers: `n` and `k`. Write a function that finds $C_k^n$.

### Example:
| Input | Output |
| :-----: | :------: |
| 10 4 | 210 |
| 5 0 | 1|


## Task 06 - Magic number

You are given positive integer `n`. Write a function that checks if `n` is "magic" number. A "magic" number is a number that is equal to the sum of its divisors (except itself).

### Example:
| Input | Output |
| :-----: | :------: |
| 28 | true |
| 12 | false |

### Explanation:

- 28 = 1 + 2 + 4 + 7 + 14 <br>
- 12 = 1 + 2 + 3 + 4 + 6

## Task 07 - Biggest sum of digits

You are given a stream of positive integers untill we cancel it (Ctrl + D on Windows). Write a function that finds the number which has the highest sum of digits.

### Example:
| Input | Output |
| :-----: | :------: |
| 28 76 123 452 | 76 |
| 152 901 3071 622 1523 | 1523 |

## Task 08 - Predicates

You are given a positive integer `n`. Write a function that prints the first `n` numbers that satisfy the following predicates:
- The difference between the smallest and the largest digit in the number is 3
- The sum of the digits of the number is prime

### Example:
| Input | Output |
| :-----: | :------: |
| 7 | 14 25 30 41 47 52 58 |