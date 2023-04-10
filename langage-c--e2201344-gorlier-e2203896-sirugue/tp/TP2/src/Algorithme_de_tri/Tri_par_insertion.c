// II) Algorithme de tri
// Programme qui réalise un tri par insertion sur un tableau de 30 entiers aléatoires compris entre 0 et 50	
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Programme de tri par insertion
int main()
{
    const int N = 30;
    int TAB[N];
    int TRI[N];
    int i, j, temp;

    // initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    // remplissage du tableau avec des valeurs aléatoires entre 0 et 50
    for (i = 0; i < N; i++) 
    {
        TAB[i] = rand() % 51;
        printf("%d ", TAB[i]);
    }
    printf("\n");

    // tri par insertion
    TRI[0] = TAB[0];
    for (i = 1; i < N; i++) 
    {
        j = i;
        while (j > 0 && TAB[i] < TRI[j-1]) 
        {
            TRI[j] = TRI[j-1];
            j--;
        }
        TRI[j] = TAB[i];
    }

    // copie du tableau trié dans TAB
    for (i = 0; i < N; i++) 
    {
        TAB[i] = TRI[i];
    }

    // affichage du tableau trié
    for (i = 0; i < N; i++) 
    {
        printf("%d ", TAB[i]);
    }
    printf("\n");

    return 0;
}
