#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159 // Définition de la constante PI
#define MAX_INPUT 25 // Définition de la taille maximale de la chaîne d'entrée

int main() 
{
    float rayon, perimetre, surface;
    char input[MAX_INPUT];

    printf("Entrez la valeur du rayon du cercle en cm: ");
    fgets(input, sizeof(input), stdin); //évite les dépassements de mémoire
    rayon = strtof(input, NULL);//interpréter une valeur à virgule flottante dans une chaîne d'octets de manière sécurisée évite les injections
    if (rayon == 0 && strcmp(input, "0") != 0) // Vérifie si la conversion a échoué
    {
        printf("Entrée invalide.\n");
        return 1;
    }
    if (rayon < 0)  // Test si le rayon est négatif
    {
        printf("Le rayon ne peut pas être négatif.\n");
    }
    else
    {
        perimetre = 2 * PI * rayon; // Calcul du périmètre
        surface = PI * rayon * rayon; // Calcul de la surface

        // Affichage des résultats
        printf("Le périmètre du cercle est : %f cm.\n", perimetre);
        printf("La surface du cercle est : %f cm.\n", surface);
    }
    return 0;
}
