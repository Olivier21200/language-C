/*Ce programme  */
#include <stdio.h>

int main() 
{
    //déclaration de la variable X
    float X;

    float x = 10 / 3;
    printf("x = %f\n", x);

    float x = 10.0 / 3;
    printf("x = %f\n", x);

    float x = 10.0 / 3.0;
    printf("x = %f\n", x);

    float x = (float) 10 / 3;
    printf("x = %f\n", x);

    float x = ((float) 10) / 3;
    printf("x = %f\n", x);

    float x2 = ((float) 10) / 3;
    printf("x6 (1 chiffre) = %.1f\n", x2);
    printf("x6 (5 chiffres) = %.5f\n", x2);

    return 0;
}
