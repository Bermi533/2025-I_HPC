#include "functions.h" //le digo que lo busque en la carpeta, no en la ruta estándar del sistema operativo

REAL sumup(int nterms)
{
    // todo
    REAL result = 0.0;
    for (int n = 1; n <= nterms; n++) {
        result += 1.0/n;
    }
    return result;
}

REAL sumdown(int nterms)
{
    REAL result = 0.0;
    for (int n = nterms; n >= 1; n--) {
        result += 1.0/n;
    }
    return result;
}