// imprima los numeros del 1 al 10 usando while
#include <iostream> 

/*int main(void) 
{
    int n;

    n = 1;
    while (n <= 10) {
        std::cout << n << std::endl;
        ++n; 
    } 

    return 0;
}
*/

int main(void)
{
    for(int i = 1; i<= 10; i = i + 1)
    {std::cout << i << std::endl;
    }
    return 0;
}

// i = i + 1 => ++i