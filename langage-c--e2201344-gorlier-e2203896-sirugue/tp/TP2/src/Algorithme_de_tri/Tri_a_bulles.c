// II) Algorithme de tri
// Programme qui réalise un tri à bulles sur un tableau de 30 entiers aléatoires compris entre 0 et 50
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Programme de tri à bulles
int main()
{
    const int N = 30;
    int TAB[N];
    int i, j, temp;
    int permutation = 1;

    // initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    // remplissage du tableau avec des valeurs aléatoires entre 0 et 50
    for (i = 0; i < N; i++) 
    {
        TAB[i] = rand() % 51;
        printf("%d ", TAB[i]);
    }
    printf("\n");

    // tri à bulles
    while (permutation) 
    {
        permutation = 0;
        for (i = 0; i < N-1; i++) 
        {
            if (TAB[i] > TAB[i+1]) 
            {
                temp = TAB[i];
                TAB[i] = TAB[i+1];
                TAB[i+1] = temp;
                permutation = 1;
            }
        }
    }

    // affichage du tableau trié
    for (i = 0; i < N; i++) 
    {
        printf("%d ", TAB[i]);
    }
    printf("\n");

    return 0;
}
