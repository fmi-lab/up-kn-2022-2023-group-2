#include <iostream>

//=========================================
// REALIZATION OF FUNCTIONS FROM <cstring>

size_t strlen2(const char str[])
{
    size_t i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

void strcpy2(char dest[], const char src[])
{
    size_t i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

//=========================================

void toUpperCase(char str[])
{
    size_t i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 'a' - 'A';
        }
        i++;
    }
}

int atoi(const char str[])
{
    int result = 0;
    size_t i = str[0] == '-' ? 1 : 0;
    bool isNegative = str[0] == '-';

    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    if (isNegative)
    {
        return -result;
    }
    return result;
}

void longestWord(const char str[])
{
    unsigned max = 0, i = 0, current = 0, startMax = 0, endMax = 0, currentStart = 0;
    while (str[i])
    {
        if (str[i] == ' ')
        {
            if (current > max)
            {
                max = current;
                endMax = i;
                startMax = currentStart;
            }
            currentStart = i + 1;
            current = 0;
        }
        else
        {
            current++;
        }
        i++;
    }

    // in case the last word in the sentence is the longest
    if (current > max)
    {
        endMax = i;
        startMax = currentStart;
    }

    while (startMax != endMax + 1)
    {
        std::cout << str[startMax];
        startMax++;
    }
}

void trim(char str[])
{
    size_t i = 0, j = strlen2(str) - 1;
    while (str[i] == ' ')
    {
        i++;
    }
    while (str[j] == ' ')
    {
        j--;
    }
    for (size_t k = 0; k <= j - i; k++)
    {
        str[k] = str[k + i];
    }

    // DON'T FORGET
    str[j - i + 1] = '\0';
}

void decode(char destination[], const char source[])
{
    unsigned times = 0;
    size_t i = 0, j = 0;
    while (source[i])
    {
        if (source[i] >= '0' && source[i] <= '9')
        {
            times = times * 10 + (source[i] - '0');
        }
        else if (source[i] >= 'a' && source[i] <= 'z')
        {
            if (times == 0)
            {
                destination[j++] = source[i];
            }
            else
            {
                for (size_t k = 0; k < times; k++)
                {
                    destination[j++] = source[i];
                }
                times = 0;
            }
        }
        i++;
    }

    // DON'T FORGET
    destination[j] = '\0';
}

// different solution from the one we did in class
int findWord(const char str[], const char word[])
{
    size_t i = 0;
    while (str[i])
    {
        size_t current = i, j = 0;
        while (word[j] && str[i] && str[i] == word[j])
        {
            j++;
            i++;
        }
        if (!word[j])
        {
            return current;
        }
        i = current + 1;
    }
    return -1;
}

void removeWord(char str[], const char word[])
{
    int index = findWord(str, word);
    while (index != -1)
    {
        char result[255]{};

        size_t i = 0, j = 0;
        while (str[i])
        {
            if (i < index || i > index + strlen2(word))
            {
                result[j++] = str[i];
            }
            i++;
        }
        strcpy2(str, result);
        index = findWord(str, word);
    }
}

void reverseSentence(char destination[], const char source[])
{
    size_t k = 0, count = 0;
    for (int i = strlen2(source) - 1; i >= 0; i--)
    {
        if (source[i] == ' ')
        {
            for (size_t j = 0; j < count; j++)
            {
                destination[k++] = source[i + j + 1];
            }
            destination[k++] = ' ';
            count = 0;
        }
        else
        {
            count++;
        }
    }

    // add the first word
    for (size_t j = 0; j < count; j++)
    {
        destination[k++] = source[j];
    }

    // DON'T FORGET
    destination[k] = '\0';
}

void replace(char str[], const char word1[], const char word2[])
{
    int index = findWord(str, word1);
    while (index != -1)
    {
        char result[255]{};

        size_t j = 0;
        for (size_t i = 0; i < index; i++)
        {
            result[j++] = str[i];
        }

        size_t k = 0;
        while (word2[k])
        {
            result[j++] = word2[k++];
        }
        result[j++] = ' ';

        for (size_t i = index + strlen2(word1) + 1; i < strlen2(str); i++)
        {
            result[j++] = str[i];
        }

        strcpy2(str, result);
        index = findWord(str, word1);
    }
}

int main()
{
    char str[] = "I am the best programmer ever";
    replace(str, "programmer", "boxer");
    std::cout << str;
    return 0;
}