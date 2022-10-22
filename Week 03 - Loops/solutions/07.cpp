#include <iostream>

int main() {
    unsigned a,b,c;
    std::cin>>a>>b>>c;
    unsigned lastFirst = a;
    unsigned lastSecond = a;
    
    for (size_t i = a; i <= b; i++)
    {
        for (size_t j = a; j <= b; j++)
        {
            if(i + j == c) {
                lastFirst = i;
                lastSecond = j;
            }
        }
    }
    
    if(lastFirst + lastSecond == c) {
        std::cout<<lastFirst<<" + "<<lastSecond<<" = "<<c;
    }
    else {
        std::cout<<"Such combination doesn't exist";
    }
    
    return 0;
}