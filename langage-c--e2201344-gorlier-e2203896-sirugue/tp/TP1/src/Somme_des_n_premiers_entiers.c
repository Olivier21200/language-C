//IX) Somme des n premiers entiers
// Programme qui calcule la somme des n premiers entiers avec différentes boucles
#include <stdio.h>

int main() 
{
    int n, i, somme;

    printf("Entrez un entier n : ");
    scanf("%d", &n);

    // boucle for à indice incrémenté
    somme = 0;
    for (i = 1; i <= n; i++)  
    {
        somme += i;
    }
    printf("La somme des %d premiers entiers (for incrémenté) est : %d\n", n, somme);

    // boucle for à indice décrémenté
    somme = 0;
    for (i = n; i >= 1; i--) 
    {
        somme += i;
    }
    printf("La somme des %d premiers entiers (for décrémenté) est : %d\n", n, somme);

    // boucle while à indice incrémenté
    somme = 0;
    i = 1;
    while (i <= n) 
    {
        somme += i;
        i++;
    }
    printf("La somme des %d premiers entiers (while incrémenté) est : %d\n", n, somme);

    // boucle while à indice décrémenté
    somme = 0;
    i = n;
    while (i >= 1) 
    {
    
        somme += i;
        i--;
    }
    printf("La somme des %d premiers entiers (while décrémenté) est : %d\n", n, somme);

    return 0;
}
