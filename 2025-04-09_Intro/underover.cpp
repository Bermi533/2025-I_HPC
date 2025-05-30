/*
#include <iostream>
#include <cstdlib>

typedef float REAL;

int main(int argc, char **argv)
{
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    int N = std::atoi(argv[1]);
    REAL under = 1.0, over = 1.0;

    while(under!=0){
        under = under/2.0;
        std::cout << under << std::endl;
    }

    while(over>1.0){
        over *= 2.0 ;
        std::cout << over << std::endl;
    }
    
}*/

#include <iostream>
#include <cstdlib>

typedef double REAL;

int main(int argc, char **argv)
{
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    int N = std::atoi(argv[1]);
    REAL under = 1.0, over = 1.0;

    //TODO
    for (int ii = 0; ii < N; ++ii){
      under /= 2.0;
      over *= 2.0;
      std::cout << ii << "\t"
                << under << "\t"
                << over << "\n";
    }

    return 0;
}