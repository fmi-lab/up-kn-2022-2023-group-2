#include <iostream>

int main()
{
    unsigned n;
    std::cin >> n;
    unsigned sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    std::cout << sum;
    return 0;
}