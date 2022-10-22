#include <iostream>

int main()
{
    unsigned n;
    std::cin >> n;

    if (n == 1 || n == 2)
    {
        std::cout << 1;
    }
    else
    {
        unsigned first = 1;
        unsigned second = 1;
        for (size_t i = 2; i < n; i++)
        {
            unsigned temp = second;
            second = first + second;
            first = temp;
        }
        std::cout<<second;
    }

    return 0;
}