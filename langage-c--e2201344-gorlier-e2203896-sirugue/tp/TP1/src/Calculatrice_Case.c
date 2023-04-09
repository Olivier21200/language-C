//VIII) Calculatrice #2 
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
        if (operation == 's') 
        {
            break;
        }
        printf("Entrez deux opérandes : ");
        scanf("%f %f", &operande1, &operande2);
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
            default:
                printf("Erreur : opération non définie\n"); // On affiche un message d'erreur si l'opération n'est pas définie
                continue;
        }
        printf("Résultat : %f\n", resultat); // On affiche le résultat
    }
    return 0;
}
