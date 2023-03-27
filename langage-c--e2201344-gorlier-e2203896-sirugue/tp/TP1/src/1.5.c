/*La division  */

#include <stdio.h>

int main() 
{
    float x1 = 10 / 3; // division entière suivie d'une conversion implicite
    printf("x1 = %f (en float) ou %d (en entier)\n", x1, (int) x1);
    
    float x2 = 10.0 / 3; // division de deux flottants
    printf("x2 = %f\n", x2);

    float x3 = 10.0 / 3.0; // division de deux flottants
    printf("x3 = %f\n", x3);

    float x4 = (float) 10 / 3; // conversion explicite suivie d'une division entière
    printf("x4 = %f\n", x4);

    float x5 = ((float) 10) / 3; // conversion explicite suivie d'une division entière
    printf("x5 = %f\n", x5);

    float x6 = ((float) 10) / 3; // conversion explicite suivie d'une division entière avec précision
    printf("x6 = %.1f (en float) ou %.5f (en float avec précision)\n", x6, x6);
    
    return 0;
}

