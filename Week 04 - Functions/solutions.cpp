#include <iostream>
#include <cmath>
#include <limits>

//===================================================
// Functions that we will need in the following tasks

double cube(double n)
{
    return n * n * n;
}

bool isPrime(unsigned n)
{
    for (unsigned i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

unsigned factorial(unsigned n)
{
    unsigned result = 1;
    for (unsigned i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

unsigned sumOfDigits(unsigned n)
{
    unsigned sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

unsigned largestDigit(unsigned n)
{
    unsigned max = 0;
    while (n > 0)
    {
        if (n % 10 > max)
        {
            max = n % 10;
        }
        n /= 10;
    }
    return max;
}

unsigned smallestDigit(unsigned n)
{
    unsigned min = std::numeric_limits<unsigned>::max();
    while (n > 0)
    {
        if (n % 10 < min)
        {
            min = n % 10;
        }
        n /= 10;
    }
    return min;
}

bool firstPredicate(unsigned n)
{
    return largestDigit(n) - smallestDigit(n) == 3;
}

bool secondPredicate(unsigned n)
{
    return isPrime(sumOfDigits(n));
}

//===================================================
// The solution of each task is in separate function
// Call the function for a particular task in main
// in order to run it

void task01()
{
    unsigned n, counter = 0;
    double sum = 0;
    std::cin >> n;
    while (n != 0)
    {
        sum += n;
        counter++;
        std::cout << sum / counter << '\n';
        std::cin >> n;
    }
}

void task02()
{
    unsigned n, i = 1;
    std::cin >> n;
    while (cube(i) < n)
    {
        std::cout << cube(i) << ' ';
        i++;
    }
}

void task03()
{
    unsigned n;
    std::cin >> n;
    for (size_t i = 1; i <= n; i++)
    {
        std::cout << 2 * cube(i) + 3 * i << ' ';
    }
}

void task04()
{
    unsigned n, i = 2, counter = 0;
    std::cin >> n;
    while (counter < n)
    {
        if (isPrime(i))
        {
            std::cout << i << ' ';
            counter++;
        }
        i++;
    }
}

void task05()
{
    unsigned n, k;
    std::cin >> n >> k;
    std::cout << factorial(n) / (factorial(k) * factorial(n - k));
}

void task06()
{
    unsigned n, sum = 0;
    std::cin >> n;
    for (unsigned i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    std::cout << std::boolalpha << (sum == n);
}

void task07()
{
    unsigned n, maxSum = 0, maxNumber = 0;
    while (std::cin >> n)
    {
        if (sumOfDigits(n) >= maxSum)
        {
            maxSum = sumOfDigits(n);
            maxNumber = n;
        }
    }
    std::cout << maxNumber;
}

void task08()
{
    unsigned n, counter = 0, i = 0;
    std::cin >> n;
    while (counter < n)
    {
        if (firstPredicate(i) && secondPredicate(i))
        {
            std::cout << i << ' ';
            counter++;
        }
        i++;
    }
}

int main()
{
    return 0;
}