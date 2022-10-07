#include <iostream>

int main()
{
    int year;
    std::cin >> year;

    bool is_divisible_by_4 = year % 4 == 0;
    bool is_divisible_by_100 = year % 100 == 0;
    bool is_divisible_by_400 = year % 400 == 0;

    std::cout << std::boolalpha << ((is_divisible_by_4 && !is_divisible_by_100) || is_divisible_by_400) << '\n';
    //std::boolalpha shows true and false instead of 1 and 0 on the console
    
    return 0;
}