#include <iostream>

int main() {
    char c;
    std::cin>>c;

    char capital = c - ('a' - 'A'); //think about how this line works

    std::cout<<capital<<std::endl;

    return 0;
}