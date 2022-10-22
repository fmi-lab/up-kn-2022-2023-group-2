#include <iostream>

int main()
{
    double x;
    int n;
    std::cin >> x >> n;
    double result = 1;

    if (n < 0)
    {
        x = 1 / x;
        n = -n;
    }

    while (n > 0)
    {
        if(n % 2 == 1) {
            result *= x;
        }

        x *= x;
        n /= 2;
    }

    std::cout << result;

    return 0;
}
