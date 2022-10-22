#include <iostream>

int main() {
    unsigned n;
    std::cin>>n;
    unsigned product = 1;
    
    for (size_t i = 1; i <= n; i++)
    {
        product *= i;
    }

    std::cout<<product;
    
    return 0;
}