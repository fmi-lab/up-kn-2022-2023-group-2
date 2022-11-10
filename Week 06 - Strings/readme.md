# Exercise 06 - String

## Instruction:
If you want to use some of the functions from the `cstring` library, you have to write them yourselves.

## Task 01 - To upper case

```c++
void toUpperCase(char str[]);
```

Write a function that transform a string into upper case.

### Bonus:
Instead of transforming to upper case, encode the string using ROT13 substitution cipher.

### Example:

```c++
char str[] = "Hello Jimmy!";
toUpperCase(str);
std::cout<<str; // -> HELLO JIMMY!
```

## Task 02 - ASCII to integer

```c++
int atoi(const char str[]);
```

Write a function that as a parameter accepts string, that starts with an integer, and returns only the integer.

### Example:

```c++
std::cout << atoi("123filler") + atoi("-81morefiller") << '\n'; // -> 42
```

## Task 03 - Longest Word

```c++
void longestWord(const char str[]);
```

Write a function that accepts string, representing a sentence, and prints the longest word in it.

### Example:

```c++
longestWord("Hello, my name is Ivancho"); // -> Ivancho
```

## Task 04 - Trim

```c++
void trim(char str[]);
```

Write a function that removes leading and trailing whitespaces in a string.

### Example:

```c++
char str[] = "    Hello World     ";
trim(str);
std::cout<<str; // -> Hello World
```

## Task 05 - Run Length Decode

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

## Task 06 - Find word

```c++
int findWord(const char str[], const char word[]);
```

Write a function that finds a word in a sentence and returns the index of the first letter of the word in the sentence. If there is not such word returns -1.

### Example:

```c++
std::cout<<findWord("I am the best programmer ever", "programmer"); // -> 14
```

## Task 07 - Remove word

```c++
void removeWord(char str[], const char word[]);
```
Write a function that removes all instances of a word from a sentence (if present).

### Example:

```c++
char str[] = "I am the best programmer ever";
removeWord(str, "programmer");
std::cout<<str; // -> I am the best ever
```

## Task 08 - Reverse sentence

```c++
void reverseSentence(char destination[], const char source[]);
```

Write a function that reverses the order of the words in a sentence and saves the new sentence in a `source` string.

### Example:

```c++
char buffer[255]{};
std::cout<<reverseSentence(buffer, "May the force be with you"); // -> you with be force the May
```

## Task 09 - Replace word
```c++
void replace(char str[], const char word1[], const char word2[]);
```
Write a function that replaces every instance of `word1` in a sentence with `word2`.

### Example:
```c++
char str[] = "I am the best programmer ever";
removeWord(str, "programmer", "boxer");
std::cout<<str; // -> I am the best boxer ever
```