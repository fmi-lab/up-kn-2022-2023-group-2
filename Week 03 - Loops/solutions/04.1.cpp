#include <iostream>

int main() {
    double x;
    int n;
    std::cin>> x>>n;
    double result = 1;

    if(n < 0) {
        x = 1/x;
        n = -n;
    }

    for (size_t i = 0; i < n; i++)
    {
        result *= x;
    }
    
    std::cout<<result;

    return 0;
}