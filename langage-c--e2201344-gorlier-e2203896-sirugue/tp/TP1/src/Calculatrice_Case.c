// VIII) Calculatrice #2 
// Programme qui permet de faire des calculs simples (+, -, *, /) avec deux opérandes et des valeurs entières ou flottantes avec l'opérateur switch
#include <stdio.h>

int main() 
{
    char operation;
    float operande1, operande2, resultat;
    while(1) 
    {
        printf("Entrez une opération (+, -, *, /) ou 's' pour sortir : ");
        scanf(" %c", &operation);

        // Validation de l'opération entrée par l'utilisateur
        if (operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != 's') 
        {
            printf("Erreur : opération non valide\n");
            continue;
        }

        if (operation == 's') 
        {
            break;
        }

        printf("Entrez deux opérandes : ");
        if (scanf("%f %f", &operande1, &operande2) != 2)
        {
            printf("Erreur : entrée invalide\n");
            // Vider le tampon d'entrée pour éviter les problèmes de boucle infinie
            while (getchar() != '\n');
            continue;
        }

        switch(operation) 
        {
            case '+': // On effectue l'opération +
                resultat = operande1 + operande2;
                break;
            case '-': // On effectue l'opération -
                resultat = operande1 - operande2;
                break;
            case '*': // On effectue l'opération *
                resultat = operande1 * operande2;
                break;
            case '/': // On effectue l'opération /
                if (operande2 != 0)  // On vérifie que l'opérande 2 n'est pas nul
                {
                    resultat = operande1 / operande2;
                } 
                else // On affiche un message d'erreur si l'opérande 2 est nul
                {
                    printf("Erreur : division par zéro\n");
                    continue;
                }
                break;
        }

        printf("Résultat : %f\n", resultat); // On affiche le résultat
    }

    return 0;
}
