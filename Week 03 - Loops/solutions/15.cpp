#include <iostream>

int main()
{
    unsigned n;
    std::cin >> n;

    for (size_t i = 0; i <= n; i++)
    {
        for (size_t j = 0; j <= n / 2; j++)
        {
            for (size_t k = 0; k <= n / 5; k++)
            {
                if (i * 1 + j * 2 + k * 5 == n)
                {
                    if (i)
                    {
                        std::cout << i << " * 1";
                    }
                    if (i && j)
                    {
                        std::cout << " + " << j << " * 2";
                    }
                    if (!i && j)
                    {
                        std::cout << j << " * 2";
                    }
                    if (k && (i || j))
                    {
                        std::cout << " + " << k << " * 5";
                    }
                    if (k && !i && !j)
                    {
                        std::cout << k << " * 5";
                    }
                    std::cout << '\n';
                }
            }
        }
    }

    return 0;
}