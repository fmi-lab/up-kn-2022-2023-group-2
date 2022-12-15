#include <iostream>

void print(const int *begin, const int *end)
{
    if (begin != end)
    {
        std::cout << *begin << ' ';
        print(begin + 1, end);
    }
}

int sumInterval(int a, int b)
{
    if (a > b)
    {
        return 0;
    }

    return a + sumInterval(a + 1, b);
}

unsigned countDigits(unsigned n)
{
    if (n == 0)
    {
        return 0;
    }

    return 1 + countDigits(n / 10);
}

unsigned gcdRec(unsigned a, unsigned b)
{
    if (a == 0)
    {
        return b;
    }

    return gcdRec(b % a, a);
}

double quickPow(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (n < 0)
    {
        return quickPow(1 / x, -n);
    }

    if (n % 2 == 0)
    {
        return quickPow(x * x, n / 2);
    }
    else
    {
        return x * quickPow(x * x, n / 2);
    }
}

const int *findFirstEven(const int *begin, const int *end)
{
    if (begin == end)
    {
        return nullptr;
    }

    if (*begin % 2 == 0)
    {
        return begin;
    }

    return findFirstEven(begin + 1, end);
}

bool isSorted(const int *begin, const int *end)
{
    if (end - begin == 2)
    {
        return *begin < begin[1];
    }

    return *begin < begin[1] && isSorted(begin + 1, end);
}

bool isPalindrome(const int *begin, const int *end)
{
    if (begin == end - 1)
    {
        return true;
    }

    if (begin + 1 == end - 1)
    {
        return *begin == *(end - 1);
    }

    return *begin == *(end - 1) && isPalindrome(begin + 1, end - 1);
}

const int *lower_bound(const int *begin, const int *end, int element)
{
    if (begin == end)
    {
        return nullptr;
    }

    if (*begin >= element)
    {
        return begin;
    }

    const int *mid = (begin + (end - begin) / 2);

    return *mid > element ? lower_bound(begin, mid, element) : lower_bound(mid + 1, end, element);
}

void printReverse(const char *str)
{
    if (!*str)
    {
        return;
    }

    printReverse(str + 1);
    std::cout << *str;
}

int currentMaxRepeated(const int *begin, const int *end, const int element, size_t counter, size_t max)
{
    if (begin == end)
    {
        return counter < max ? max : counter;
    }

    if (*begin != element)
    {
        return counter < max ? currentMaxRepeated(begin + 1, end, *begin, 1, max) : currentMaxRepeated(begin + 1, end, *begin, 1, counter);
    }
    else
    {
        return currentMaxRepeated(begin + 1, end, *begin, counter + 1, max);
    }
}

int maxRepeated(const int *begin, const int *end)
{
    return currentMaxRepeated(begin + 1, end, *begin, 1, 0);
}

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

int toNumber(char c)
{
    return c - '0';
}

int *extractNumber(const char *str, int *destination, int result)
{
    if (!*str)
    {
        return destination;
    }

    if (!isDigit(*str))
    {
        return extractNumber(str + 1, destination, 0);
    }

    if (isDigit(*str) && toNumber(*str) % 2 == 0 && !isDigit(str[1]))
    {
        *destination = result * 10 + toNumber(*str);
        return extractNumber(str + 1, destination + 1, 0);
    }

    return extractNumber(str + 1, destination, result * 10 + toNumber(*str));
}

int *extractEvens(const char *source, int *destination)
{
    return extractNumber(source, destination, 0);
}

void towersOfHanoi(unsigned n, char rod1, char rod2, char rod3)
{
    if (n == 0)
    {
        return;
    }

    towersOfHanoi(n - 1, rod1, rod3, rod2);
    std::cout << "Move disc " << n << " from rod " << rod1 << " to rod " << rod3 << '\n';
    towersOfHanoi(n - 1, rod2, rod1, rod3);
}

int main()
{
    std::cout << gcdRec(72, 90); // -> 18
}