#include <iostream>

int main() {
    int a, b;
    std::cin>>a>>b;
    int p_health = 100;
    int g_health = 100;
    int turn = 1;
    while (p_health > 0 && g_health > 0)
    {
        if(turn % 2) {
            g_health -= a;
            if(g_health <= 0) {
                std::cout<<"Pesho won in the " << turn << "th turn\n";
            }
            else {
                std::cout<<"Pesho reduced Gosho to "<<g_health<<" health.\n";
            }
        }
        else {
            p_health -= b;
            if(p_health <= 0) {
                std::cout<<"Gosho won in the " << turn << "th turn\n";
            } else {
                std::cout<<"Gosho reduced Pesho to "<<p_health<<" health.\n";
            }
        }

        if(turn % 3 == 0 && p_health > 0 && g_health > 0) {
            p_health+=10;
            g_health+=10;
        }
        turn++;
    }
    
    return 0;
}