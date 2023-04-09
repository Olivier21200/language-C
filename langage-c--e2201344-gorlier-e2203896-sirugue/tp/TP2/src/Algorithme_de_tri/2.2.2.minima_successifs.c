#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// programme de tri par recherche des minima successifs
int main()
{
    const int N = 30;
    int TAB[N];
    int i, j, min, temp;

    // initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    // remplissage du tableau avec des valeurs aléatoires entre 0 et 50
    for (i = 0; i < N; i++) 
    {
        TAB[i] = rand() % 51;
        printf("%d ", TAB[i]);
    }
    printf("\n");

    // tri par recherche des minima successifs
    for (i = 0; i < N-1; i++) 
    {
        min = i;
        for (j = i+1; j < N; j++) 
        {
            if (TAB[j] < TAB[min]) 
            {
                min = j;
            }
        }
        if (min != i) 
        {
            temp = TAB[i];
            TAB[i] = TAB[min];
            TAB[min] = temp;
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
