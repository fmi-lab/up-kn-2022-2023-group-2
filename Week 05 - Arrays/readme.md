# Exercise 05 - Arrays

## Intructions:

Follow the given signatures of the functions. Write example program for each task to show that your functions are correct. In the programs make all the arrays with max size of 255 and validate the input.

## Task 01 - Print Array

```c++
void print(const int arr[], size_t size);
```
Write a function that prints all the elements of an array.

### Example:

```c++
int arr[] = {16, 23, 7, 18, 39};
print(arr, 5); // -> 16 23 7 18 39
```

## Task 02 - Find Maximum Element

```c++
int findMax(const int arr[], size_t size);
```
Write a function that returns the maximum element in an array. 

### Example:

```c++
int arr[] = {5, 7, 2, 3, 6};
std::cout<<findMax(arr, 5); // -> 7
```

## Task 03 - Find element

```c++
int find(const int arr[], size_t size, int element);
```
Write a function that finds element in array and returns the index of the first occurence. If there is not such element in the array return -1.

### Example:
```c++
int arr[]{8, 0, 2, 6, 9, 2, 7};
std::cout<<find(arr, 7, 2); // -> 5
std::cout<<find(arr, 7, 16); // -> -1
```

## Task 04 - Filter

```c++
unsigned filter(int destination[], const int source[], size_t size);
```
Write a function, that finds those elements in `source` that are even and are divisible by 7, and stores them in `destination` array and returns the new size of `destination`.

### Example:
```c++
int source[]{5,7,28,6,98,24,14,68};
int destination[255];
int size = filter(destination, source, 8);
print(destination, size); // -> 28 98 14
```

## Task 05 - Set

```c++
bool isSet(const int arr[], size_t size);
```
Write a function that checks if array is set. We define a set as a sorted range with no repeating elements.

### Example:
```c++
int arr1[]{2, 5, 6, 11, 17};
int arr2[]{2, 5, 5, 11, 17};
std::cout<<isSet(arr1, 5); // -> true
std::cout<<isSet(arr2, 5); // -> false
```

## Task 06 - Reverse

```c++
void reverse(int arr[], size_t size);
```
Write a function that reverses an array.

### Example:

```c++
int arr[]{0, 1, 2, 3, 4};
reverse(arr, 5);
print(arr, 5); // -> 4 3 2 1 0
```

## Task 07 - Most common element

```c++
int mostCommon(const int arr[], size_t size);
```
Write a function that returns the element with most occurences in an array.

### Example:

```c++
int arr[]{4, 1, 1, 4, 2, 3, 4, 4, 1, 2, 4, 9, 3};
std::cout << mostCommon(arr, 13); // -> 4
```

## Task 08 - Sort

```c++
void sort(int arr[], size_t size);
```
Write a function that sorts array in ascending order. Make 2 different versions - one with `selection sort` and the other with `bubble sort`.

### Example:

```c++
int arr[]{10, 5, 8, 3, 13, 7};
sort(arr, 6);
print(arr, 6); // -> 3 5 7 8 10 13
```

---

## Task 09 - To upper case

```c++
void toUpperCase(char str[]);
```
Write a function that transform a string into upper case.

### Example:
```c++
char str[] = "Hello Jimmy!";
toUpperCase(str);
std::cout<<str; // -> HELLO JIMMY!
```

## Task 10 - ASCII to integer

```c++
int atoi(const char str[]);
```
Write a function that as a parameter accepts string, that starts with an integer, and returns only the integer.

### Example:
```c++
std::cout << atoi("123filler") + atoi("-81morefiller") << '\n'; // -> 42
```

## Task 11 - Longest Word

```c++
void longestWord(const char str[]);
```
Write a function that accepts string, representing a sentence, and prints the longest word in it.

### Example:
```c++
longestWord("Hello, my name is Ivancho"); // -> Ivancho
```

## Task 12 - Run Length Decode

```c++
void decode(char destination[], const char source[]);
```
Write a function that "decodes" a `source` string and saves the result in `destination` string. To "decode" a string means to replace every occurence of {number}{character} with {number times character}.

### Example:
```c++
char buffer[255]{};
std::cout<<decode(buffer, "a2b10c"); // -> abbcccccccccc
```

### Bonus:
Write a function that encodes a string using the before mentioned algorythm.

## Task 13 - Reverse sentence

```c++
void reverseSentence(char destination[], const char source[]);
```
Write a function that reverses the order of the words in a sentence and saves the new sentence in a `source` string.

### Example:
```c++
char buffer[255]{};
std::cout<<reverseSentence(buffer, "May the force be with you"); // -> you with be force the May
```