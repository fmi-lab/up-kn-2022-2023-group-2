#include <iostream>

int main()
{
    unsigned n;
    std::cin >> n;
    unsigned a = n % 10;
    n /= 10; // This is the same as n = n / 10; The same syntaxis works for all other arythmetic operations
    unsigned b = n % 10;
    n /= 10;
    unsigned c = n % 10;
    n /= 10;

    unsigned result = a * 1000 + b * 100 + c * 10 + n;

    std::cout << result << std::endl;

    return 0;
}