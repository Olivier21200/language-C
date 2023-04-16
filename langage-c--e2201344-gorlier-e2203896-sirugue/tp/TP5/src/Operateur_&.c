/*
* TP 5 : Pointeurs
*
* : lecture de l'adresse des éléments d'un tableau
*/
#include <stdio.h>
#define N 5
void main()
{
    int i;
    int t[N] = {10, 20, 30, 40, 50};
    for(i=0;i<N;i++)
    {
        printf("t[%d] = %d ; &t[%d] = %u\n",i,t[i],i,&t[i]);
    }    
}

//Question n°1 : Qu’observe-t-on lors de l’exécution de ce programme ?
//#On observe que chaque élément du tableau est affiché avec son adresse mémoire correspondante. 
//#Pour chaque itération de la boucle, le format d'affichage de la ligne de sortie est "t[i] = valeur ; &t[i] = adresse". 
//#La valeur de chaque élément du tableau est stockée dans la variable t[i] et son adresse mémoire est obtenue avec l'opérateur "&" dans &t[i]. 
//#On peut donc observer les adresses mémoire de chaque élément du tableau ainsi que leur valeur.

//Question n°2 : Illustrez sous forme d’un schéma (plan mémoire) similaire à celui de la Figure 1 la représentation en mémoire du tableau « t ».
//#La représentation en mémoire du tableau "t" peut être illustrée à l'aide d'un schéma similaire à celui de la Figure 1, 
//en considérant que chaque élément du tableau est représenté par une case mémoire.

//Adresses Mémoire
// 0  --> t[0]=10
// 4  --> t[1]=20
// 8  --> t[2]=30
// 12 --> t[3]=40
// 16 --> t[4]=50

//#Figure 2. Représentation en mémoire du tableau "t"
//#ans ce schéma, chaque élément du tableau "t" est stocké dans une case mémoire consécutive, 
//#avec une taille de 4 octets (pour le type "int" sur la plupart des architectures). 
//#Ainsi, l'élément t[0] est stocké à l'adresse mémoire 0, t[1] est stocké à l'adresse mémoire 4 
//#(décalage de 4 octets par rapport à t[0]), t[2] est stocké à l'adresse mémoire 8, et ainsi de suite.
//#Le nombre d'octets réservés pour chaque élément du tableau dépend du type de données utilisé pour le tableau. 
//#Par exemple, si le type de données utilisé est "short int", chaque élément du tableau ne nécessite que 2 octets au lieu de 4, 
//#tandis que si le type de données est "double", chaque élément du tableau nécessite 8 octets.

//Question n°3 : Compilez et exécutez plusieurs fois ce programme en remplaçant dans la déclaration du
//tableau « t » le type « int » par « short int », « float », « double ». Que peut-on en déduire
//sur le format de stockage des types de données mentionnés ?

//#En remplaçant le type « int » par « short int », on peut constater que les adresses des éléments du tableau sont toujours incrémentées 
//#de 2 octets, ce qui indique que les variables de type « short int » occupent 2 octets de mémoire au lieu de 4 pour les variables de type « int ».

//#En remplaçant le type « int » par « float », on peut constater que les adresses des éléments du tableau sont toujours incrémentées de 4 octets, 
//#ce qui indique que les variables de type « float » occupent 4 octets de mémoire.

//#En remplaçant le type « int » par « double », on peut constater que les adresses des éléments du tableau sont toujours incrémentées de 8 octets,
//#ce qui indique que les variables de type « double » occupent 8 octets de mémoire.

//#On peut en déduire que le format de stockage des types de données dépend de leur taille en octets et que les adresses des éléments d'un tableau 
//#sont incrémentées selon la taille de la variable utilisée.

//Question n°4 : Écrire le programme suivant et expliquer à l’aide d’un schéma son fonctionnement et sa représentation mémoire.
void main(void)
{
    int *px;
    px = (int *) malloc (sizeof(int));
    *px = 1;
    printf("Adresse de px : %X\n", &px);
    printf("Adresse pointee par le pointeur px = %X\n", px);
    printf("Valeur memorisee a l'adresse pointee par le pointeur px = %d\n\n",*px);
}

//#Le programme alloue dynamiquement de la mémoire pour stocker un entier à l'aide de la fonction malloc. 
//#Un pointeur px de type int est ensuite déclaré pour stocker l'adresse de la zone mémoire allouée.

//#Ensuite, la valeur 1 est stockée à l'adresse pointée par px en utilisant l'opérateur *.

//#Le programme affiche ensuite l'adresse de px, qui est l'adresse du pointeur lui-même, 
//#ainsi que l'adresse pointée par px et la valeur stockée à cette adresse.

//#Le schéma de la représentation mémoire du programme ressemblerait à ceci :
//#         +---+
//#px ----> |   |      +---+
//#         +---+      | 1 |
//#                    +---+