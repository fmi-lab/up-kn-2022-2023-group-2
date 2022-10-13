#include<iostream>

int main(){
    double number1, number2;
    char operation;
    std::cin>>number1>>number2>>operation;
    switch (operation){
        case '+':
            std::cout<<number1+number2;
            break;
        case '-':
            std::cout<<number1-number2;
            break;
        case '*':
            std::cout<<number1*number2;
            break;
        case '/':
            std::cout<<number1/number2;
            break;
        default:
            std::cout<<"unknown operator\n";
            break;
    }
}