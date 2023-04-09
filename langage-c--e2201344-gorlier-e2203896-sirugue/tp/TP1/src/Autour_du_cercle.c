//Autour du cercle
// Programme qui calcule le périmètre et la surface d'un cercle
#include <stdio.h>

#define PI 3.14159 // Définition de la constante PI

int main() 
{
    float rayon, perimetre, surface;

    printf("Entrez la valeur du rayon du cercle en cm: ");
    scanf("%f", &rayon);

    perimetre = 2 * PI * rayon; // Calcul du périmètre
    surface = PI * rayon * rayon; // Calcul de la surface

    // Affichage des résultats
    printf("Le périmètre du cercle est : %f cm.\n", perimetre);
    printf("La surface du cercle est : %f cm.\n", surface);

    return 0;
}
