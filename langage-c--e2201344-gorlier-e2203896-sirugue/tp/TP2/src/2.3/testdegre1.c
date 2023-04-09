#include <stdio.h>
#include "degre.h"

int main() {
    double celsius = 25.0;
    double kelvin = CelsiusAKelvin(celsius);
    double fahrenheit = CelsiusAFahrenheit(celsius);

    printf("%.2f degres Celsius = %.2f degres Kelvin\n", celsius, kelvin);
    printf("%.2f degres Celsius = %.2f degres Fahrenheit\n", celsius, fahrenheit);

    double celsius2 = KelvinACelsius(kelvin);
    double fahrenheit2 = CelsiusAFahrenheit(celsius2);

    printf("%.2f degres Kelvin = %.2f degres Celsius\n", kelvin, celsius2);
    printf("%.2f degres Celsius = %.2f degres Fahrenheit\n", celsius2, fahrenheit2);

    return 0;
}
