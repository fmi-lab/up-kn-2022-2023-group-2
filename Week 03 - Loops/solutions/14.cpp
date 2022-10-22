#include <iostream>
#include <cmath>

int main()
{
    int n;
    std::cin >> n;

    for (int i = 2; i <= n; i++)
    {
        bool isPrime = true;

        unsigned j = 2;
        while (j < sqrt(i) && isPrime)
        {
            if (i % j == 0)
            {
                isPrime = false;
            }
            j++;
        }
        
        if (n % i == 0 && isPrime)
        {
            do
            {
                std::cout << i;
                n /= i;
                if (n > 1)
                {
                    std::cout << " * ";
                }
            } while (n % i == 0);
        }
    }

    return 0;
}