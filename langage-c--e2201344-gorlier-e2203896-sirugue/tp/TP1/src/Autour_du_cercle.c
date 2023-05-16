#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159 // Définition de la constante PI

int main() 
{
    float rayon, perimetre, surface;
    char input[50];

    printf("Entrez la valeur du rayon du cercle en cm: ");
    fgets(input, sizeof(input), stdin); //évite les dépassements de mémoire
    rayon = strtof(input, NULL);//évite les attaques d'injection 

    perimetre = 2 * PI * rayon; // Calcul du périmètre
    surface = PI * rayon * rayon; // Calcul de la surface

    // Affichage des résultats
    printf("Le périmètre du cercle est : %f cm.\n", perimetre);
    printf("La surface du cercle est : %f cm.\n", surface);

    return 0;
}