#include "factorial.h"

long factorial(long number)
{
    if (number == 0 ) return 1;
    if (number < 0){
        std::cerr <<"Negative numbers not allowed. Returning -1\n";
        return -1;
    }
    return number < 0 ? number : factorial(number-1)*number; //if-else. SI es true, retorna lo que va antes de los dos puntos, si es false lo que va después
}

long Pordos(long n){
    return 2*n;
}