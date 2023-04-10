#include <stdio.h>
#include "degre.h"

int lireChoix() 
{
    int choix;
    
    printf("Choisissez une conversion :\n");
    printf("1 - Celsius vers Kelvin\n");
    printf("2 - Celsius vers Fahrenheit\n");
    printf("0 - Quitter\n");
    
    scanf("%d", &choix);
    return choix;
}

void executerChoix(int choix) 
{
    double tempCelsius;
    double tempConvertie;
    
    printf("Entrez la temperature a convertir en degres Celsius : ");
    scanf("%lf", &tempCelsius);
    
    switch (choix) 
    {
        case 1:
            tempConvertie = CelsiusAKelvin(tempCelsius);
            printf("%.1f degres Celsius = %.1f degres Kelvin\n", tempCelsius, tempConvertie);
            break;
        case 2:
            tempConvertie = CelsiusAFahrenheit(tempCelsius);
            printf("%.1f degres Celsius = %.1f degres Fahrenheit\n", tempCelsius, tempConvertie);
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
