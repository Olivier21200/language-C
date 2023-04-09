#include <stdio.h>
#include "degre.h"

int main() 
{
    float celsius = 25.0;
    float kelvin = CelsiusAKelvin(celsius);
    float fahrenheit = CelsiusAFahrenheit(celsius);
    
    printf("%.2f degres Celsius = %.2f degres Kelvin\n", celsius, kelvin);
    printf("%.2f degres Celsius = %.2f degres Fahrenheit\n", celsius, fahrenheit);
    
    return 0;
}
