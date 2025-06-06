#include <iostream>
#include <cmath>

typedef float REAL;

REAL sum1(int N);
REAL sum2(int N);

int main(void){
    int N = 100;

    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);

    REAL S1;
    REAL S2;

    for(int n = 1; n <= N; n++){
        S1 = sum1(n);
        S2 = sum2(n);

        std::cout << n << "\t" << S1 << "\t" << S2 << "\t" << std::fabs(1 - S1 / S2) << "\n";
    }

    return 0;  
}

REAL sum1(int N){
    REAL suma = 0.0;

    for(int k = 1; k <= N; k++){
        REAL n = k * 1.0;
        suma += 1 / n;
    }

    return suma;
}

REAL sum2(int N){
    REAL suma = 0.0;

    for(int k = N; k >= 1; k--){
        REAL n = k * 1.0;
        suma += 1 / n;
    }

    return suma;
}
