#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "degre.h"

int lireChoix() 
{
    int choix;
    char input[10];

    printf("Choisissez une conversion :\n");
    printf("1 - Celsius vers Kelvin\n");
    printf("2 - Celsius vers Fahrenheit\n");
    printf("0 - Quitter\n");

    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &choix);

    return choix;
}

void executerChoix(int choix) 
{
    double tempCelsius;
    double tempConvertie;
    char input[20];

    printf("Entrez la température à convertir en degrés Celsius : ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%lf", &tempCelsius);
    
    switch (choix) 
    {
        case 1:
            tempConvertie = CelsiusAKelvin(tempCelsius);
            printf("%.1f degrés Celsius = %.1f degrés Kelvin\n", tempCelsius, tempConvertie);
            break;
        case 2:
            tempConvertie = CelsiusAFahrenheit(tempCelsius);
            printf("%.1f degrés Celsius = %.1f degrés Fahrenheit\n", tempCelsius, tempConvertie);
            break;
        default:
            printf("Choix invalide.\n");
            break;
    }
}

int main() 
{
    int choix = 1;
    
    while (choix != 0) 
    {
        choix = lireChoix();
        executerChoix(choix);
    }
    
    return 0;
}
