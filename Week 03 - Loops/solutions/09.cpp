#include <iostream>

int main()
{
    unsigned n;
    std::cin >> n;
    int counter = 0;
    int current = 0;

    for (int i = 0; i < n; i++)
    {
        int number;
        std::cin >> number;
        if (counter != 0)
        {
            if (current == number)
            {
                counter++;
            }
            else
            {
                counter--;
            }
        }
        else
        {
            current = number;
            counter = 1;
        }
    }

    std::cout << current << '\n';

    return 0;
}