// X) PGCD
// Programme qui calcule le PGCD de deux nombres entiers positifs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 50

int main() 
{
    int X, N;
    long int resultat = 1;
    char input[MAX_INPUT_SIZE];
    
    // Saisie sécurisée des valeurs de X et N
    printf("Entrez deux nombres entiers X et N :\n"); 
    
    printf("X = ");
    fgets(input, sizeof(input), stdin);
    X = atoi(input);
    
    printf("N = ");
    fgets(input, sizeof(input), stdin);
    N = atoi(input);
    
    if (X <= 0 || N < 0) // Vérification des valeurs de X et N
    {
        printf("Erreur : X doit être strictement positif et N doit être positif\n");
        return 1;
    }
    
    // Calcul du résultat en évitant le débordement
    for (int i = 0; i < N; i++) 
    {
        if (resultat > __INT_MAX__ / X) 
        { // Vérification du débordement potentiel
            printf("Erreur : débordement arithmétique\n");
            return 1;
        }
        resultat *= X;
    }
    
    printf("%d^%d = %ld\n", X, N, resultat); // Affichage du résultat
    
    return 0;
}
