#include <iostream>

int main() {
    unsigned n, digit;
    std::cin >> n >> digit;

    unsigned a = n % 10;
    n /= 10;
    unsigned b = n % 10;
    n /= 10;
    unsigned c = n % 10;
    n /= 10;
    
    std::cout<<((a == digit) || (b == digit) || (c == digit) || (n == digit))<<'\n';

    return 0;
}