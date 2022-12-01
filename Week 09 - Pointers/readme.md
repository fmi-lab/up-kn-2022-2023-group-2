# Exercise 09 - Pointers

## Intructions: 
We define range as a pair of pointers - its beginning and its end. All of today's tasks are simplified implementations of functions from the `<algorythm>` library. You can try to implement the rest for homework (bare in mind that some of them require you to know about lambda functions, dynamic memory and structs). In every function the parameter `end` refers to the element after the last element in the range (while you do the tasks, think why we don't pass the last element). Try to reuse as much of the functions as possible.

## Task 01 - Upper Bound
```c++
const int* upper_bound(const int* begin, const int* end, int element);
```

Write a function that, by a given `sorted` range and element, finds the position of the first element that is bigger than the given one. If there is no such element return `nullptr`. Use the binary search method to reduce the number of iterations.

### Example:
```c++
const int arr[]{0, 1, 2, 5};
const int *element = upper_bound(std::begin(arr), std::end(arr), 4);
const int *notFound = upper_bound(std::begin(arr), std::begin(arr) + 2, 4);

element ? std::cout << *element << '\n' : std::cout << "There are no bigger elements than 4\n"; // -> 5
notFound ? std::cout << *notFound << '\n' : std::cout << "There are no bigger elements than 4\n"; // -> There are no bigger elements than 4
```

## Task 02 - Equal
```c++
bool equal(const int* first_begin, const int* first_end, const int* second_begin, const int* second_end);
```

Write a function that checks if two ranges contain the same elements.

### Example:
```c++
const int arr[]{1, 2, 1, 3};
const int arr2[]{1, 2};

std::cout << std::boolalpha << equal(std::begin(arr), std::begin(arr) + 2, std::begin(arr2), std::end(arr2))<<'\n'; // -> true
std::cout << std::boolalpha << equal(std::begin(arr) + 2, std::end(arr), std::begin(arr2), std::end(arr2)); // -> false
```

## Task 03 - Replace
```c++
void replace(int* begin, int* end, int old_value, int new_value);
```

Write a function that replaces all occurences of `old_value` in a range with `new_value`.

### Example:
```c++
int arr[]{0, 9, 2, 9, 3, 9};
replace(std::begin(arr), std::end(arr), 9, 1);
print(std::begin(arr), std::end(arr)); // -> 0 1 2 1 3 1
```

## Task 04 - Rotate
```c++
void rotate(int* begin, int* mid, int* end);
```

Write a function that, by a given range and midpoint inside of it, swaps the elements in the range so that the range [mid, end) goes to the start and the range [begin, mid) goes to the end.

### Example:
```c++
int arr[]{0, 1, 2, 3, 4};
rotate(std::begin(arr), std::begin(arr)+2, std::end(arr));
print(std::begin(arr), std::end(arr)); // -> 2 3 4 0 1
```

## Task 05 - Search
```c++
const int* search(const int* first_begin, const int* first_end, const int* second_begin, const int* second_end);
```

Write a function that, by given 2 ranges, finds the position of the first occurence of the second range in the first. If there is not such occurence, return `nullptr`.

### Example:
```c++
const int arr[]{0, 1, 2, 1, 2};
const int seq[]{1, 2};
const int* begin = search(std::begin(arr), std::end(arr), std::begin(seq), std::end(seq));
print(begin, std::end(arr)); // -> 1 2 1 2
```

## Task 06 - Ends With
```c++
bool ends_with(const int* first_begin, const int* first_end, const int* second_begin, const int* second_end);
```

Write a functions that checks if a range ends with another range.

### Example:
```c++
const int arr[]{2, 4, 5, 3, 7, 6};
const int arr2[]{7, 6};

std::cout<<std::boolalpha<<ends_with(std::begin(arr), std::end(arr), std::begin(arr2), std::end(arr2)) << '\n'; // -> true
std::cout<<std::boolalpha<<ends_with(std::begin(arr), std::begin(arr) + 5, std::begin(arr2), std::end(arr2)); // -> false
```

## Task 07 - Find End
```c++
const int* find_end(const int* first_begin, const int* first_end, const int* second_begin, const int* second_end);
```

Write a function that, by given 2 ranges, finds the beginning of the last occurence of the second range in the first. If there is not such occurence, return `nullptr`.

### Example:
```c++
const int arr[]{0, 1, 2, 1, 2, 5};
const int seq[]{1, 2};
const int* begin = find_end(std::begin(arr), std::end(arr), std::begin(seq), std::end(seq));
print(begin, std::end(arr)); // -> 1 2 5
```

## Task 08 - Unique
```c++
int* unique(int* begin, int* end);
```

Write a function that removes all, except the first element, from every consecutive group of equivalent elements and returns the new logical end of the range.

### Example:
```c++
int arr[]{1, 2, 1, 1, 3, 3, 3, 4, 4, 5, 4};
int* end = unique(std::begin(arr), std::end(arr));
print(std::begin(arr), end); // -> 1 2 1 3 4 5 4
```

## Task 09 - Partition
```c++
int* partition(const int* begin, const int* end);
```
Write a function that puts all odd elements at the start of the range and all even ones - at the end and return the beginning of the subrange, containing the even elements. The order of the elements in each group doesn't matter.

### Example:
```c++
int arr[] {4, 7, 1, 3, 2, 6, 5, 9, 0};
int* evenBegin = partition(std::begin(arr), std::end(arr));
print(std::begin(arr), evenBegin); // -> 7 1 3 5 9
std::cout<<'\n';
print(evenBegin, std::end(arr)); // -> 4 2 6 0
``` 

## Task* 10 - Next Permutation
```c++
bool next_permutation(int* begin, int* end);
```

Write a function that changes a range into its next possible (in lexicographical order) permutation of its elements. If the range is in the last permutation (is sorted in decreasing order), resets it to the first one  (sorted in increasing order) and returns `false`. Otherwise returns `true`.

### Example:
```c++
int arr[]{1, 2, 3};

do
{
    print(std::begin(arr), std::end(arr));
    std::cout << std::endl;
} while(next_permutation(std::begin(arr), std::end(arr)));

/*
    1 2 3
    1 3 2
    2 1 3
    2 3 1
    3 1 2
    3 2 1
*/
```