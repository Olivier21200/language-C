#include "degre.h"

float CelsiusAKelvin(float celsius) 
{
    return celsius + 273.15;
}

float KelvinACelsius(float kelvin) 
{
    return kelvin - 273.15;
}

float CelsiusAFahrenheit(float celsius) 
{
    return (celsius * 9.0 / 5.0) + 32.0;
}

float FahrenheitACelsius(float fahrenheit) 
{
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}
