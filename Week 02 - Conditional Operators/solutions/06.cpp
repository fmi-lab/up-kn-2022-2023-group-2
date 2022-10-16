#include <iostream>

int main() 
{
    int a, b, c;
    std::cin >> a >> b >> c;
 
    int max = a > b ? a > c ? a : c : b > c ? b : c;
    int min = a < b ? a < c ? a : c : b < c ? b : c;
    int mid = a > b ? b > c ? b : a > c ? c : a : a > c ? a : c < b ? c : b; //think how you can find mid using max and min

    std::cout<<min << ' ' << mid << ' ' << max;

    return 0;
}