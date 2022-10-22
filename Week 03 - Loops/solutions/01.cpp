#include <iostream>
#include <limits>

int main() {
    unsigned n;
    std::cin>>n;
    int max = std::numeric_limits<int>::min(); //the minimum value of int
    for (size_t i = 0; i < n; i++)
    {
        int a;
        std::cin>>a;
        if(a > max) {
            max = a;
        }
    }
    std::cout << max;
    return 0;
}