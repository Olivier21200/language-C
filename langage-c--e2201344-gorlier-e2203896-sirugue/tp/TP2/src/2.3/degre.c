#include "degre.h"

double CelsiusAKelvin(double celsius) 
{
    return celsius + 273.15;
}

double KelvinACelsius(double kelvin) 
{
    return kelvin - 273.15;
}

double CelsiusAFahrenheit(double celsius) 
{
    return (celsius * 9.0 / 5.0) + 32.0;
}

double FahrenheitACelsius(double fahrenheit) 
{
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}
