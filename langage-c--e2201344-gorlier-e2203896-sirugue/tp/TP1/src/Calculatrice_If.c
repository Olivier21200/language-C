// VIII) Calculatrice
// Programme qui permet de faire des calculs simples (+, -, *, /) avec deux opérandes et des valeurs entières ou flottantes
#include <stdio.h>

int main() {
    char operation; // Variable pour stocker l'opération
    float operande1, operande2, resultat; // Variables pour stocker les opérandes et le résultat

    while (1) 
    {
        printf("Entrez une opération (+, -, *, /) ou 's' pour sortir : ");
        if (scanf(" %c", &operation) != 1)
        { // Lecture sécurisée de l'opération
            printf("Erreur de saisie.\n");
            fflush(stdin); // Efface les caractères restants dans le flux d'entrée
            continue;
        }
        
        if (operation == 's') 
        { // Vérifie si l'utilisateur veut sortir
            break;
        }

        printf("Entrez deux opérandes : ");
        if (scanf("%f %f", &operande1, &operande2) != 2) 
        { // Lecture sécurisée des opérandes
            printf("Erreur de saisie.\n");
            fflush(stdin);
            continue;
        }

        if (operation == '+') 
        { // Addition
            resultat = operande1 + operande2;
        } 
        else if (operation == '-') 
        { // Soustraction
            resultat = operande1 - operande2;
        } 
        else if (operation == '*') 
        { // Multiplication
            resultat = operande1 * operande2;
        } 
        else if (operation == '/') 
        { // Division
            if (operande2 != 0) 
            { // Vérifie si le deuxième opérande est différent de zéro pour éviter la division par zéro
                resultat = operande1 / operande2;
            } 
            else 
            {
                printf("Erreur : division par zéro\n");
                continue;
            }
        } 
        else 
        { // Opération non définie
            printf("Erreur : opération non définie\n");
            continue;
        }
        printf("Résultat : %f\n", resultat); // Affichage du résultat
    }
    return 0;
}
