// X) PGCD
// Programme qui calcule le PGCD de deux nombres entiers positifs
#include <stdio.h>

int main() 
{
    int X, N;
    long int resultat = 1;
    
    // Saisie des valeurs de X et N
    printf("Entrez deux nombres entiers X et N :\n"); 
    printf("X = ");
    scanf("%d", &X);
    printf("N = ");
    scanf("%d", &N);
    
    if (X <= 0 || N < 0) // Vérification des valeurs de X et N
    {
        printf("Erreur : X doit être strictement positif et N doit être positif\n");
        return 1;
    }
    
    for (int i = 0; i < N; i++) // Calcul de X^N
    {
        resultat *= X;
    }
    
    printf("%d^%d = %ld\n", X, N, resultat); // Affichage du résultat
    
    return 0;
}
