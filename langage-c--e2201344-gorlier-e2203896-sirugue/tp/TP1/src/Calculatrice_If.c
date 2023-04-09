// VIII) Calculatrice
// Programme qui permet de faire des calculs simples (+, -, *, /) avec deux opérandes et des valeurs entières ou flottantes 
#include <stdio.h>

int main() {
    char operation;
    float operande1, operande2, resultat;
    while(1) 
    {
        printf("Entrez une opération (+, -, *, /) ou 's' pour sortir : ");
        scanf(" %c", &operation);
        if (operation == 's')  // On quitte la boucle si l'utilisateur entre 's'
        {
            break;
        }
        printf("Entrez deux opérandes : ");
        scanf("%f %f", &operande1, &operande2);
        if (operation == '+')  // On effectue l'opération +
        {
            resultat = operande1 + operande2;
        } 
        else if (operation == '-') // On effectue l'opération -
        {
            resultat = operande1 - operande2;
        } 
        else if (operation == '*') // On effectue l'opération *
        {
            resultat = operande1 * operande2;
        } 
        else if (operation == '/') // On effectue l'opération /
        {
            if (operande2 != 0) // On vérifie que l'opérande 2 n'est pas nul
            {
                resultat = operande1 / operande2;
            } 
            else // On affiche un message d'erreur si l'opérande 2 est nul
            {
                printf("Erreur : division par zéro\n");
                continue;
            }
        } else // On affiche un message d'erreur si l'opération n'est pas définie
        {
            printf("Erreur : opération non définie\n");
            continue;
        }
        printf("Résultat : %f\n", resultat); // On affiche le résultat
    }
    return 0;
}
