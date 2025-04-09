#include <iostream>
#include <string>

int main(void)
{
    std::string name;
    std::cout << "Oiga parceritx, escriba su nombre:" << std::endl;
    //std::cin >> name;
    std::getline(std::cin, name);
    std::cout << "Hola " +  name + " " + "<3" + "\n";
    return 0;
}