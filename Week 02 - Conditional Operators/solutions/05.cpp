#include <iostream>

int main() {
    unsigned n;
    std::cin >> n;
    std::cout<<(n >= 18 ? "You are good to go\n" : "You are underaged\n");
    return 0;
}