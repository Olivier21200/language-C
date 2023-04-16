void echangerPointeurs(int **ppa, int **ppb)
{
    int *tmp;
    tmp = *ppa;
    *ppa = *ppb;
    *ppb = tmp;
}

//#Q1 Expliquer le fonctionnement de la procédure suivante
//La fonction "echangerPointeurs" prend en entrée deux pointeurs de pointeurs d'entiers (int **ppa et int **ppb). 
//Elle utilise ces pointeurs de pointeurs pour échanger les adresses mémoire de deux variables entières pointées.

//Plus précisément, elle utilise un pointeur intermédiaire tmp pour stocker l'adresse pointée par le premier pointeur 
//**ppa, puis elle affecte à *ppa l'adresse pointée par le deuxième pointeur **ppb. Ensuite, elle affecte à *ppb 
//l'adresse stockée dans tmp, qui correspond à l'adresse pointée par le premier pointeur **ppa avant l'échange.

//Ainsi, cette fonction permet de permuter les adresses pointées par deux pointeurs de pointeurs, 
//et donc de modifier les valeurs pointées par ces derniers.

//#Q2 Écrire une fonction « main » similaire à celle proposée dans III), et qui illustre l’utilisation de cette procédure.
#include <stdio.h>

void echangerPointeurs(int **ppa, int **ppb)
{
    int *tmp;
    tmp = *ppa;
    *ppa = *ppb;
    *ppb = tmp;
}

int main()
{
    int x = 10, y = 20;
    int *px = &x, *py = &y;

    printf("Avant échange : x = %d ; y = %d\n", *px, *py);
    echangerPointeurs(&px, &py);
    printf("Après échange : x = %d ; y = %d\n", *px, *py);

    return 0;
}
//Dans cette fonction "main", on crée deux variables entières x et y, ainsi que deux pointeurs d'entiers px et py qui 
//pointent respectivement sur x et y. On affiche ensuite les valeurs de x et y avant l'échange, puis on appelle la fonction 
//"echangerPointeurs" en lui passant les adresses de px et py en tant qu'arguments. Enfin, on affiche les valeurs de x et y 
//après l'échange pour vérifier que les adresses pointées par px et py ont bien été échangées, et donc que les valeurs 
//pointées par ces pointeurs ont également été échangées.