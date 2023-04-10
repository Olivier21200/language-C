#include <stdio.h>
#include "degre.h"

int main() 
{
    double tempCelsius = 20.0;
    double tempKelvin = CelsiusAKelvin(tempCelsius);
    double tempFahrenheit = CelsiusAFahrenheit(tempCelsius);
    
    printf("%.1f degres Celsius = %.1f degres Kelvin\n", tempCelsius, tempKelvin);
    printf("%.1f degres Celsius = %.1f degres Fahrenheit\n", tempCelsius, tempFahrenheit);
    
    return 0;
}
