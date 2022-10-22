#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for (size_t i = 1; i <= n / 2 * 2 + 1; i += 2)
    {
        for (size_t j = 0; j < (n / 2 * 2 + 1 - i) / 2; j++)
        {
            std::cout << ' ';
        }

        for (size_t j = 0; j < i; j++)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }

    for (size_t i = 0; i < n / 2; i++)
    {
        std::cout << ' ';
    }
    std::cout << '|';
    
    return 0;
}