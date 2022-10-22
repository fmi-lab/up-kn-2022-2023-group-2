#include <iostream>
#include <cmath>

int main() {
    unsigned n;
    std::cin >> n;
    bool isPrime = true;

    unsigned i = 2;
    while (i < sqrt(n) && isPrime)
    {
        if(n % i == 0) {
            isPrime = false;
        }
        i++;
    }

    std::cout<<(n == 1 ? "Neither prime nor composite" : isPrime ? "Prime" : "Composite");
    
    return 0;
}