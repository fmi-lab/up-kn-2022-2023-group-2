# Exercise 03 - Loops

## Task 01 - Max Number

You are given a positive number `n` and `n` consecutive numbers. Find the max number among them.

### Example:
| Input | Output |
| :--------- | :------: |
| 5 <br> 4 2 8 3 6 | 8 |
| 7 <br> 14 5 63 75 59 0 46 | 75 |

## Task 02 - Sum of Range

You are given 2 numbers `a` and `b`. Find the sum of all numbers in the interval [a, b].

### Example:
| Input | Output |
| :-----: | :------: |
| 1 <br> 100 | 5050 |
| -7 <br> 26 | 323 |

## Task 03 - Factorial

You are given a positive number `n`. Find `n!`.

### Example:
| Input | Output |
| :-----: | :------: |
| 5 | 120 |
| 10 | 3628800 |

## Task 04 - Power

You are given 2 numbers - `x` and `n`. Find x<sup>n</sup>. Don't use the function `pow` from `<cmath>`.

### Example:
| Input | Output |
| :-----: | :------: |
| 2 8 | 256 |
| -5 3 | -125 |

## Task 05 - Prime number

You are given a number. Check if it is prime.

### Example:
| Input | Output |
| :-----: | :------: |
| 7 | Prime |
| 63 | Composite |
| 1 | Neither prime nor composite |

## Task 06 - Fibonacci

You are given a positive number `n`. Find the `n`-th Fibonacci number.

### Example:
| Input | Output |
| :-----: | :------: |
| 6 | 8 |
| 10 | 55 |

## Task 07 - Game of numbers

You are given 3 positive numbers `a`, `b` and `c`. Find the last combination of 2 numbers in the interval [`a`, `b`] in which the sum of the two numbers is equal to `c`. If there is not a combination with that sum print "Such combination doesn't exist".

### Example:
| Input | Output |
| :-----: | :------: |
| 1 <br> 10 <br> 5 | 4 + 1 = 5 |
| 23 <br> 24 <br> 100 | Such combination <br> doesn't exist |

### Explanation:

First example: All combinations between 1 and 10 are: 1 1, 1 2, 1 3, ... , 4 0, <strong>4 1</strong>, 4 2, ... ,10 9, 10 10. The combination 4 1 is the last in which the sum is 5.

Second example: All combinations between 23 and 24 are: 23 23, 23 24, 24 23, 24 24. Neither of them has sum 100.

## Task 08 - Christmas Tree

You are given a positive number `n`. Draw christmas tree like in the example.

### Example:
```
n = 5:   *   
        *** 
       ***** 
         |   


n = 8:    *    
         ***   
        *****  
       ******* 
      *********
          |             
```

## Task 09 - Supermajority

You are given a positive number `n` and `n` consecutive integers, one of which appears more than the rest of the numbers `combined`. Find that number (You aren't allowed to use arrays).

### Example:
| Input | Output |
| :-----: | :------: |
| 5 <br> 1 2 1 3 1| 1 |
| 4 <br> 1 2 1 3 | ??? |

### Explanation:
In the first example there are three 1s which is more than half of the numbers - 1 is supermajority.

In the second example there are two 1s which is exactly half of the numbers - 1 is NOT supermajority. However, in the requirements it is stated that there will always be a number that is supermajority. Therefor this input is illegal. Assume that there won't be such an input.

## Task 10 - Count of digits

You are given a number. Count the number of its digits.

### Example:
| Input | Output |
| :-----: | :------: |
| 257 | 3 |
| 58126 | 5 |

## Task 11 - Sum of digits

You are given a number. Find the sum of its digits.

### Example:
| Input | Output |
| :-----: | :------: |
| 257 | 14 |
| 58126 | 22 |

## Task 12 - Neighbourhood War

Gosho and Pesho are neighbours, but after a conflict they are at war. Write a program to simulate this war. Gosho attacks on every even turn of the game while Pesho attacks  on every odd turn. You will receive how much damage these attacks do from the console. After every turn print "{turn player} reduced {other player} to {health of attacked player} health."
Both players start with 100 Health points. On every third turn Pesho and Gosho restore 10 Health Points. Health points are restored after the attack is made.
When one of the player’s health is below or equal to zero you should stop any other further operations and print who the winner is and in which turn he won.

### Example:
| Input | Output |
| :----- | :-------------------------------: |
| 30 <br> 40 | Pesho reduced Gosho to 70 health. <br> Gosho reduced Pesho to 60 health. <br> Pesho reduced Gosho to 40 health. <br> Gosho reduced Pesho to 30 health. <br> Pesho reduced Gosho to 20 health. <br> Gosho won in the 6th turn. |

## Task 13 - Greatest Common Divisor

You are given 2 positive numbers `a` and `b`. Find their Greatest Common Divisor (GCD).

### Example:
| Input | Output |
| :-----: | :------: |
| 20 <br> 28 | 4 |
| 98 <br> 56 | 14 |

## Task 14 - Product of prime factors

You are given a positive number. Output it as product of prime factors.

### Example:
| Input | Output |
| :-----: | :------: |
| 24 | 2 * 2 * 2 * 3 |
| 98 | 2 * 7 * 7 |

## Task 15 - Combinations

You are given a number n. Find all the combinations of the numbers
1, 2, 5, 10, 20, 50 and 100 to add up to the number n.

### Example
| Input | Output |
| :-----: | :------: |
| 7 | 7*1, 1*2 + 5*1, 2*2 + 3*1, 3*2 + 1*1, 1*5 + 2*1, 1*5 + 1*2 |
