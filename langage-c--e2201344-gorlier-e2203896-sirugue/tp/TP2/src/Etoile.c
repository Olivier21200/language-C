// II ) Etoile
// Programme qui affiche des étoiles en fonction du choix de l'utilisateur (1 à 6) et de la valeur de N (entre 1 et 20)

#include <stdio.h>

int main() 
{
    int N, choix;

    do // Boucle pour demander à l'utilisateur de saisir une valeur entre 1 et 20
    {
        printf("Entrez un entier entre 1 et 20 : ");
        scanf("%d", &N);
    }
    while (N < 1 || N > 20); // Tant que N n'est pas compris entre 1 et 20, on redemande à l'utilisateur de saisir une valeur

    do { // Boucle pour afficher le menu et demander à l'utilisateur de saisir un choix
        printf("\n----- Menu principal -----\n");
        printf("1) Afficher un carré\n");
        printf("2) Afficher une pyramide montante\n");
        printf("3) Afficher une pyramide descendante\n");
        printf("4) Afficher un sapin de Noël\n");
        printf("5) Afficher un losange\n");
        printf("6) Quitter\n");

        printf("\nEntrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) // Affichage des étoiles en fonction du choix de l'utilisateur
        {
            case 1: // Affichage d'un carré de côtés N  
                for (int i = 0; i < N; i++) 
                {
                    for (int j = 0; j < N; j++) 
                    {
                        printf("*");
                    }
                    printf("\n");
                }
                break;
            case 2: // Affichage d'une pyramide montante de hauteur N
                for (int i = 1; i <= N; i++) // Affichage de la partie supérieure du triangle inversé
                {
                    for (int j = 0; j < i; j++) 
                    {
                        printf("*");
                    }
                    printf("\n");
                }
                for (int i = N-1; i >= 1; i--) // Affichage de la partie inférieure du triangle inversé
                {
                    for (int j = 0; j < i; j++) 
                    {
                        printf("*");
                    }
                    printf("\n");
                }
                break;
            case 3: // Affichage d'une pyramide descendante de hauteur N
                for (int i = 1; i <= N; i++) // Affichage de la partie supérieure du triangle
                {
                    for (int j = N; j > i; j--) 
                    {
                        printf(" ");
                    }
                    for (int k = 1; k <= i; k++) 
                    {
                        printf("*");
                    }
                    printf("\n");
                }
                for (int i = 1; i < N; i++) // Affichage de la partie inférieure du triangle
                {
                    for (int j = 1; j <= i; j++) 
                    {
                        printf(" ");
                    }
                    for (int k = N; k > i; k--) 
                    {
                        printf("*");
                    }
                    printf("\n");
                }
                break;
            case 4: // Affichage d'un sapin de Noël de hauteur N
                for (int i = 1; i <= N; i++)
                {
                    for (int j = 1; j <= N - i; j++) // Affichage des espaces avant les étoiles
                    {
                        printf(" ");
                    }
                    for (int j = 1; j <= 2 * i - 1; j++) // Affichage des étoiles
                    {
                        printf("*");
                    }
                    printf("\n");
                }
                // Affichage du tronc du sapin
                for (int i = 0; i < N - 1; i++) 
                {
                    for (int j = 1; j < N; j++) 
                    {
                        printf(" ");
                    }
                    printf("*\n");
                }
                break;
            case 5: // Affichage d'un losange de hauteur N
            for (int i = 1; i <= N; i++) // Affichage de la partie supérieure du losange
            {
                for (int j = 1; j <= N - i; j++) 
                {
                    printf(" ");
                }
                for (int j = 1; j <= 2 * i - 1; j++) 
                {
                    printf("*");
                }
                printf("\n");
            }
            for (int i = N - 1; i >= 1; i--) // Affichage de la partie inférieure du losange
            {
                for (int j = 1; j <= N - i; j++) 
                {
                    printf(" ");
                }
                for (int j = 1; j <= 2 * i - 1; j++) 
                {
                    printf("*");
                }
                printf("\n");
            }
            break;
            case 6: // Quitter le programme
                printf("Fin du programme !");
                break;
            default: // Si l'utilisateur saisit un choix invalide
                printf("Choix invalide.\n");
        }
    } 
    while (choix != 6); // Tant que l'utilisateur ne saisit pas 6, on lui redemande de saisir un choix
    return 0;
}