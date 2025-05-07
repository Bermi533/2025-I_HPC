#include <iostream>
#include <cmath>

typedef float REAL;

REAL sumk1(int N);
REAL sumk2(int N);

int main(void)
{
    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);

    for (int N = 1; N <= 1000000; ++N)
    {
        REAL s1 = sumk1(N);
        REAL s2 = sumk2(N);
        std::cout << N << "\t"
                  << s1 << "\t"
                  << s2 << "\t"
                  << std::fabs(1 - s1/s2) << "\n";
    }

    return 0;
}

REAL sumk1(int N)
{
    REAL suma1 = 0.0;
    for (int a = 1; a <= N; ++a)
    {
        REAL b = a/1.0;
        suma1 += 1/b;
    }
    return suma1;
}

REAL sumk2(int N)
{
    REAL suma2 = 0.0;
    for(int c = N; c >= 1; --c)
    {
        REAL d = c/1.0;
        suma2 += 1/d;
    }
    return suma2;
}