/*
* TP 5 : Pointeurs
*
* insuffisance des appels de fonction
* avec passage par valeur
*/
#include <stdio.h>

void echanger(int a, int b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void main()
{
    int x,y;
    x = 12;
    y = 34;
    printf("Avant échange : x = %d ; y = %d\n",x,y);
    echanger(x,y);
    printf("Après échange : x = %d ; y = %d\n",x,y);
}

//#Q1 Expliquer, à l’aide de schémas et en détaillant les étapes de l’exécution, pourquoi le programme ci-dessus ne fonctionne pas.
//       main()                  echanger()
//         |                         |
//         |                         |
//         v                         v
//    x = 12, y = 34           a = 12, b = 34
//         |                         |
//         |                         |
//         v                         v
//echanger(x, y)            tmp = a; a = b; b = tmp;
//         |                         |
//         |                         |
//         v                         v
//    x = 12, y = 34           a = 34, b = 12
//         |                         |
//         |                         |
//         v                         v
//  Affiche x et y          Retourne sans modifier x et y
//Comme le montre le schéma, les variables a et b sont des copies locales de x et y, 
//respectivement, et les échanges effectués dans la fonction echanger() 
//ne modifient pas les valeurs de x et y dans la fonction main().

//#Q2 Corriger ce programme en remplaçant les paramètres entiers « a » et « b » de la procédure « échanger » par des pointeurs d’entiers « pa » et « pb »
#include <stdio.h>

void echanger(int* pa, int* pb)
{
    int tmp;
    tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

void main()
{
    int x,y;
    x = 12;
    y = 34;
    printf("Avant échange : x = %d ; y = %d\n",x,y);
    echanger(&x,&y);
    printf("Après échange : x = %d ; y = %d\n",x,y);
}
//Dans cette version corrigée, les paramètres de la fonction echanger sont des pointeurs d'entiers (int*), 
//qui permettent à la fonction de modifier les valeurs des variables x et y dans la fonction main. 
//Les modifications sont réalisées en utilisant les opérateurs * (pour accéder à la valeur pointée par le pointeur) 
//et & (pour obtenir l'adresse d'une variable). Ainsi, lorsque la fonction echanger est appelée avec les adresses de x et y 
//comme arguments (echanger(&x, &y)), elle modifie directement les valeurs de x et y en utilisant les pointeurs pa et pb.

//#Q3 Expliquer, à l’aide de schémas et en détaillant les étapes de l’exécution, pourquoi le programme corrigé fonctionne.
//Dans cette version corrigée, la fonction echanger prend en entrée deux pointeurs d'entiers (int*) qui correspondent aux adresses de deux variables dans la fonction main.
//Ainsi, lorsque la fonction echanger est appelée avec les adresses de x et y (echanger(&x, &y)),
//les pointeurs pa et pb de la fonction echanger sont initialisés avec ces adresses.
//Lorsque les valeurs des variables pointées par ces pointeurs sont échangées, les variables x et y dans la fonction main sont modifiées en conséquence.
//Voici les étapes détaillées de l'exécution :

// main() echanger(pa, pb)
// | |
// | |
// v v
// x = 12, y = 34 pa = &x, pb = &y
// | |
// | |
// v v
//echanger(&x, &y) tmp = *pa; *pa = *pb; *pb = tmp;
// | |
// | |
// v v
// x = 34, y = 12 Retourne sans modifier x et y
// | |
// | |
// v v
// Affiche x et y Fin de la fonction main()

//Comme le montre le schéma, la fonction echanger utilise les pointeurs pa et pb pour accéder aux valeurs de x et y dans la fonction main,
//puis échange ces valeurs en utilisant une variable temporaire tmp.
//En fin de compte, la fonction echanger retourne sans rien modifier dans la fonction main.
//Après l'appel de la fonction echanger, les variables x 