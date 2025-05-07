#include <iostream>
#include <iomanip>
#include <cmath>

float suma_directa(int N) {
    float s = 0.0f;
    for (int k = 1; k <= N; ++k) {
        s += 1.0f /k;
    }
    return s;
}

float suma_inversa(int N) {
    float s = 0.0f;
    for (int k = N; k>=1;--k) {
        s += 1.0f / k;
    }
    return s;
}

int main() {
    const int Nmax = 1000000;
    std::cout << std::fixed << std::setprecision(7);
    std::cout << "N\tS1\t\tS2\t\tDelta\n";
    for (int N = 1; N <= Nmax; ++N) {
        float S1 = suma_directa(N);
        float S2 = suma_inversa(N);
        float Delta = std::fabs(1.0f - S1/S2);
        std::cout
            << N << '\t' 
            << S1 << '\t'
            << S2 << '\t'
            << Delta << "\n";
    }
    return 0;
}