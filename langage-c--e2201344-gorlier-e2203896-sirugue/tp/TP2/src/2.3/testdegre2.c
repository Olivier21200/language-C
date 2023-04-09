#include <stdio.h>
#include "degre.h"

int lireChoix()
{
    int choix;
    printf("Menu de conversion :\n");
    printf("1. Convertir degrés Celsius en degrés Fahrenheit\n");
    printf("2. Convertir degrés Celsius en degrés Kelvin\n");
    printf("3. Convertir degrés Fahrenheit en degrés Celsius\n");
    printf("4. Convertir degrés Fahrenheit en degrés Kelvin\n");
    printf("5. Convertir degrés Kelvin en degrés Celsius\n");
    printf("6. Convertir degrés Kelvin en degrés Fahrenheit\n");
    printf("0. Quitter le programme\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choix);
    return choix;
}

void executerChoix(int choix)
{
    double temperature;
    switch (choix) {
        case 1:
            printf("Entrez la température en degrés Celsius : ");
            scanf("%lf", &temperature);
            printf("%.2f°C = %.2f°F\n", temperature, CelsiusAFahrenheit(temperature));
            break;
        case 2:
            printf("Entrez la température en degrés Celsius : ");
            scanf("%lf", &temperature);
            printf("%.2f°C = %.2fK\n", temperature, CelsiusAKelvin(temperature));
            break;
        case 3:
            printf("Entrez la température en degrés Fahrenheit : ");
            scanf("%lf", &temperature);
            printf("%.2f°F = %.2f°C\n", temperature, FahrenheitACelsius(temperature));
            break;
        case 4:
            printf("Entrez la température en degrés Fahrenheit : ");
            scanf("%lf", &temperature);
            printf("%.2f°F = %.2fK\n", temperature, FahrenheitAKelvin(temperature));
            break;
        case 5:
            printf("Entrez la température en degrés Kelvin : ");
            scanf("%lf", &temperature);
            printf("%.2fK = %.2f°C\n", temperature, KelvinACelsius(temperature));
            break;
        case 6:
            printf("Entrez la température en degrés Kelvin : ");
            scanf("%lf", &temperature);
            printf("%.2fK = %.2f°F\n", temperature, KelvinAFahrenheit(temperature));
            break;
        default:
            printf("Choix invalide !\n");
            break;
    }
}

int main()
{
    int choix = -1;
    while (choix != 0) {
        choix = lireChoix();
        executerChoix(choix);
    }
    printf("Au revoir !\n");
    return 0;
}
