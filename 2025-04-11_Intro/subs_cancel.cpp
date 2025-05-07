#include <iostream>
#include <cmath>

typedef float REAL;

// declaration
REAL sumk1(int k);
REAL sumk2(int k);
REAL sumk3(int k);


int main(void)
{
    //std::cout.precision(7);
    //std::cout.setf(std::ios::scientific);

    for (int k = 1; k <= 100; k++){
        std::cout << k << "\t" << sumk1(k) << "\t" << sumk2(k) << "\t" << sumk3(k) << "\t" << std::fabs(sumk1(k)-sumk3(k))/sumk3(k) << "\t" << std::fabs(sumk2(k)-sumk3(k))/sumk3(k) << "\n";
    }
    
    return 0;
}

// implementation
REAL sumk1(int k)
{
    REAL suma1 = 0.0;
    for(int ii = 1; 2*ii <= k; ii++) {
        REAL n = ii/1.0;
        suma1 += std::pow(-1.0, n) * n/(n+1.0);
    }
    return suma1;
}

REAL sumk2(int k)
{
    REAL suma2_1 = 0.0;
    REAL suma2_2 = 0.0;
    REAL suma2;
    for(int ii = 1; ii <= k; ii++) {
        REAL n = ii/1.0;
        suma2_1 += ((2.0*n - 1.0)/(2.0*n));
        suma2_2 += (2.0*n)/(2.0*n + 1.0);
        suma2 = suma2_1 + suma2_2;
    }
    return suma2;
}

REAL sumk3(int k)
{
    REAL suma3 = 0.0;
    for(int ii = 1; ii <= k; ii++) {
        REAL n = ii/1.0;
        suma3 += 1.0/(2.0*n*(2.0*n + 1.0));
    }
    return suma3;
}