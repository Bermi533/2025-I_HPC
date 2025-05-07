#include <iostream>
#include <cmath>

typedef float REAL;

// Declaraciones
REAL sumk1(int k);
REAL sumk2(int k);
REAL sumk3(int k);

int main(void)
{
    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);

    for (int k = 1; k <= 100; k++){
        REAL s1 = sumk1(k);
        REAL s2 = sumk2(k);
        REAL s3 = sumk3(k);
        std::cout << k << "\t" 
                  << s1 << "\t" 
                  << s2 << "\t" 
                  << s3 << "\t" 
                  << std::fabs(s1 - s3)/s3 << "\t" 
                  << std::fabs(s2 - s3)/s3 << "\n";
    }
    
    return 0;
}

REAL sumk1(int k)
{
    REAL suma1 = 0.0;
    for (int n = 1; n <= 2 * k; n++) {
        REAL n1 = n/1.0;
        suma1 += std::pow(-1.0, n1) * n1 / (n1 + 1.0);
    }
    return suma1;
}

REAL sumk2(int k)
{
    REAL suma2_1 = 0.0;
    REAL suma2_2 = 0.0;
    for (int n = 1; n <= k; n++) {
        REAL n1 = n/1.0;
        suma2_1 += (2.0 * n1 - 1.0) / (2.0 * n1);
        suma2_2 += (2.0 * n1) / (2.0 *n1 + 1.0);
    }
    return -suma2_1 + suma2_2;
}

REAL sumk3(int k)
{
    REAL suma3 = 0.0;
    for (int n = 1; n <= k; n++) {
        REAL n1 = n/1.0;
        suma3 += 1.0 / (2.0 * n1 * (2.0 * n1 + 1.0));
    }
    return suma3;
}
