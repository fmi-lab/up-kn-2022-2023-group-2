# Exercise 10 - Recursion

## Intructions: 
All of today's tasks need to be solved recursively. For some of the tasks you may need to use a separate function that is called recursively instead of the given in the requirements. For homework you can try to solve as much tasks as possible using tail recursion.

## Task 01 - Sum Interval
```c++
int sumInterval(int a, int b);
```

Write a function that finds the sum of all elements in the interval [a, b].

### Example:
```c++
std::cout<<sumInterval(1, 10); // -> 55
```

## Task 02 - Count Digits
```c++
unsigned countDigits(unsigned n);
```

Write a function that finds the number of digits in a number.

### Example:
```c++
std::cout<<countDigits(42891); // -> 5
```

## Task 03 - Greatest Common Divisor
```c++
unsigned gcdRec(unsigned a, unsigned b);
```

Write a function that finds the greates common divisor of 2 numbers.

### Example:
```c++
std::cout<<gcdRec(72, 90); // -> 18
```

## Task 04 - Quick Pow
```c++
double quickPow(double x, int n);
```

Write a function that finds x<sup>n</sup> using the exponentiation by squaring method. The method is as follows:
- if `n` is even then x<sup>n</sup> = x<sup> n/2 <sup>2</sup></sup>
- else x<sup>n</sup> = x*x<sup> n/2 <sup>2</sup></sup>

### Example:
```c++
std::cout<<quickPow(3, 6); // -> 729
```

## Task 05 - Find First Even
```c++
const int* findFirstEven(const int* begin, const int* end);
```

Write a function that finds the position of the first even number in a range.

### Example:
```c++
const int arr[] {5, 7, 13, 3, 6, 23, 17};

const int* firstEven = findFirstEven(std::begin(arr), std::end(arr));
print(firstEven, std::end(arr)); // -> 6 23 17
```

## Task 06 - Is Sorted
```c++
bool isSorted(const int* begin, const int* end);
```

Write a function that checks if range is sorted.

### Example:
```c++
const int arr1[] {4, 7, 11, 16, 24};
const int arr2[] {4, 7, 5, 11, 18};

std::cout<<std::boolalpha<<isSorted(std::begin(arr1), std::end(arr1))<<'\n'; // -> True
std::cout<<isSorted(std::begin(arr2), std::end(arr2))<<'\n'; // -> False
```

## Task 07 - Palindrome
```c++
bool isPalindrome(const int* begin, const int* end);
```

Write a function that checks if a range is palindrome.

### Example:
```c++
const int arr1[] {4, 7, 11, 7, 4};
const int arr2[] {4, 7, 11, 12, 7, 4};
std::cout<<std::boolalpha<<isPalindrome(std::begin(arr1), std::end(arr1))<<'\n'; // -> True
std::cout<<std::boolalpha<<isPalindrome(std::begin(arr2), std::end(arr2))<<'\n'; // -> False
```

## Task 08 - Lower Bound
```c++
const int* lower_bound(const int* begin, const int* end, int element);
```

Write a function that finds the position of the first element in a range that is not less than `element`. If there is no such element return nullptr.

### Example:
```c++
const int arr[]{6, 7, 9, 10, 12, 15};
const int *lower = lower_bound(std::begin(arr), std::end(arr), 12);

if (lower)
{
    print(lower, std::end(arr));
}
else
{
    std::cout << "No such element\n";
}
// -> 12 15
```

## Task 09 - Reverse Print
```c++
void printReverse(const char* str);
```

Write a function that prints string in reverse order.

### Example:
```c++
printReverse("Hello World"); // -> dlroW olleH
```

## Task 10 - Max Repeated
```c++
int maxRepeated(const int* begin, const int* end);
```

Write a function that finds the length of the longest subrange, containing equal elements.

### Example:
```c++
const int arr[] {1, 1, 2, 3, 3, 3, 4, 2, 2, 2, 2, 1, 1};
std::cout<<maxRepeated(std::begin(arr), std::end(arr)); // -> 4
```

## Task 11 - Extract Evens
```c++
int* extractEvens(const char* source, int* destination);
```

Write a function that extracts all even numbers from `source` string and stores them into `destination`. The function returns the new logical end of `destination`.

### Example:
```c++
int arr[255]{};
int *evensEnd = extractEvens("458sade21asd4asd42a7sd8", arr); // -> 458 4 42 8
print(std::begin(arr), evensEnd);
```

## Task 12* - Towers Of Hanoi
```c++
void towersOfHanoi(unsigned n, char rod1, char rod2, char rod3);
```

Write a function that solves the Towers of Hanoi puzzle for `n` disks and prints every step of the solution.

### Example:
```c++
towersOfHanoi(3, 'A', 'B', 'C');
/*
-> Move disk 1 from rod A to rod C
   Move disk 2 from rod A to rod B
   Move disk 1 from rod C to rod B
   Move disk 3 from rod A to rod C
   Move disk 1 from rod B to rod A
   Move disk 2 from rod B to rod C
   Move disk 1 from rod A to rod C
*/
```