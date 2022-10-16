#include <iostream>

int main()
{
    char input;
    std::cin >> input;
    if (input >= '0' && input <= '9')
    {
        std::cout << "digit\n";
    }
    else if (input >= 'a' && input <= 'z' || input >= 'A' && input <= 'Z')
    {
        std::cout << "letter\n";
    }
    else
    {
        std::cout << "special character\n";
    }

    return 0;
}