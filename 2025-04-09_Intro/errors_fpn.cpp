#include <iostream>

int main(void){
    double a = -1.5e38;
    double b = 1.5e38;
    double c = 1;

std::cout << (a+b)+c << std::endl;
std::cout << a+(b+c) << std::endl;
}