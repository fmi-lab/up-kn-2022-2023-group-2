#include <iostream>

int main() {
    unsigned n;
    std::cin >> n;

    unsigned a = n % 10;
    n /= 10;
    unsigned b = n % 10;
    n /= 10;
    unsigned c = n % 10;
    n /= 10;
    
    std::cout<<(a + b == c + n)<<'\n';

    return 0;
}