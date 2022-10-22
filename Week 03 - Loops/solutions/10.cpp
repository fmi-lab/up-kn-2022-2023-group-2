#include <iostream>

int main() {
    unsigned n;
    std::cin>>n;
    unsigned count = 0;
    while (n > 0)
    {
        count++;
        n /= 10;   
    }

    std::cout<<count;
    
    return 0;
}