#define N 3

typedef struct maillon 
{
    int x;
    struct maillon * suiv;
} maillon;

void main(void)
{
    maillon lc;
    lc.x = 1;
    printf("Valeur du champs x = %d\n\n", lc.x);
    lc.suiv = (maillon *) malloc(sizeof(maillon));
    lc.suiv->x = 2;
    printf("Valeur du champs x du deuxieme maillon = %d\n\n", lc.suiv->x);
}

//#Q1 Écrire le programme suivant et expliquer à l’aide d’un schéma son fonctionnement et sa représentation mémoire.
//Le programme suivant définit une structure de maillon qui sera utilisée pour créer une liste chaînée. 
//Cette structure contient un entier et un pointeur vers un autre maillon.

//Dans le programme principal, on crée un premier maillon lc en initialisant son champ x à 1. Ensuite, 
//on alloue dynamiquement de la mémoire pour créer un deuxième maillon lc.suiv en utilisant la fonction malloc.
//Le champ x de ce deuxième maillon est initialisé à 2. Le pointeur lc.suiv du premier maillon est alors affecté 
//pour pointer vers ce deuxième maillon.

//Le schéma suivant montre la représentation mémoire des deux maillons ainsi que le pointeur 
//lc qui pointe vers le premier maillon :

//lc         lc.suiv
//+---+      +---+
//| x |----->| x |
//+---+      +---+
//|   |----->|   |----->NULL
//+---+      +---+

//La flèche entre les deux maillons indique que lc.suiv pointe vers le deuxième maillon. 
//Le pointeur suiv du deuxième maillon est initialisé à NULL car il n'y a pas encore de troisième maillon.

//La sortie du programme affiche la valeur de lc.x (1) et la valeur de lc.suiv->x (2), 
//qui sont les valeurs des champs x du premier et du deuxième maillon, respectivement.


void main(void)
{
    maillon *lc;
    maillon *tete;
    int cpt;

    /*init des maillons*/
    lc = (maillon *) malloc(sizeof(maillon));
    tete = lc;

    //Creation des maillons en fin de liste
    for(cpt=1;cpt<N;cpt++) //pour tous les maillons à créer
    {
        lc->suiv = (maillon *) malloc(sizeof(maillon));
        lc = lc->suiv;
    }

    lc->suiv = NULL; //dernier maillon pointe vers NULL
    cpt = 0;
    lc = tete;

    //remplissage des valeurs de chacun des maillons
    while (lc != NULL) //tant que le maillon courant n'est pas le suivant du dernier maillon de la liste
    {
        lc->x = cpt; //affectation
        cpt++; //increment du compteur
        lc = lc->suiv;//passe au suivant
    }

    lc = tete;
    while (lc != NULL) //tant que le maillon courant n'est pas le suivant du dernier maillon de la liste
    {
        printf("Valeur du champs courant = %d \n",lc->x);
        printf("Adresse maillon courant= %X et du suivant %X\n",lc, lc->suiv);
        lc = lc->suiv;//passe au suivant
    }
}

//#Q2 Ecrire le programme suivant et expliquer à l’aide d’un schéma son fonctionnement et sa représentation mémoire.
//Le schéma suivant montre la représentation mémoire de la liste chaînée créée par ce programme :

//tete -> +---+ +---+ +---+ +---+
//| x |----->| x |----->| x |----->| x |
//+---+ +---+ +---+ +---+
//| | |
//| | |
//v v v
//NULL NULL NULL

//Le pointeur tete pointe vers le premier maillon de la liste. Chaque maillon contient une valeur x et un 
//pointeur suivant vers le maillon suivant dans la liste. Le dernier maillon pointe vers NULL pour indiquer la 
//fin de la liste.

//#Q3 Ecrire un programme qui construit une liste chainée de N maillons. La valeur de N sera
//#définie dans une variable globale. Ecrire une fonction permettant de supprimer un maillon
//#de la liste chainée sans briser le chainage. Le numéro du maillon à supprimer sera demandé à l’utilisateur.
#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct maillon {
    int x;
    struct maillon *suiv;
} maillon;

maillon *creerListe(int n);
void afficherListe(maillon *tete);
void supprimerMaillon(maillon **tete, int n);

int main(void) {
    maillon *tete = creerListe(N);
    printf("Liste initiale :\n");
    afficherListe(tete);

    int n;
    printf("Entrez le numéro du maillon à supprimer : ");
    scanf("%d", &n);
    supprimerMaillon(&tete, n);
    printf("Liste après suppression du maillon %d :\n", n);
    afficherListe(tete);

    return 0;
}

// Fonction pour créer une liste chaînée de n maillons
maillon *creerListe(int n) {
    maillon *tete = NULL;
    maillon *courant = NULL;

    for (int i = 0; i < n; i++) {
        maillon *nouveau = (maillon *)malloc(sizeof(maillon));
        nouveau->x = i;
        nouveau->suiv = NULL;

        if (tete == NULL) {
            tete = nouveau;
            courant = nouveau;
        } else {
            courant->suiv = nouveau;
            courant = nouveau;
        }
    }

    return tete;
}

// Fonction pour afficher une liste chaînée
void afficherListe(maillon *tete) {
    while (tete != NULL) {
        printf("%d ", tete->x);
        tete = tete->suiv;
    }
    printf("\n");
}

// Fonction pour supprimer un maillon de la liste chaînée
void supprimerMaillon(maillon **tete, int n) {
    maillon *courant = *tete;
    maillon *precedent = NULL;

    // Recherche du maillon à supprimer
    while (courant != NULL && courant->x != n) {
        precedent = courant;
        courant = courant->suiv;
    }

    if (courant == NULL) {
        printf("Maillon non trouvé.\n");
        return;
    }

    // Suppression du maillon
    if (precedent == NULL) {
        *tete = courant->suiv;
    } else {
        precedent->suiv = courant->suiv;
    }

    free(courant);
}
