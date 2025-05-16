#include <iostream>
#include "factorial.h"

int main(void)
{
    std::cout << factorial(4) << std::endl;
    std::cout << factorial(-1) << std::endl;
    std::cout << factorial(0.5) << std::endl;
    std::cout << factorial(0) << std::endl;
    std::cout << factorial(15) << std::endl;
    return 0;
}