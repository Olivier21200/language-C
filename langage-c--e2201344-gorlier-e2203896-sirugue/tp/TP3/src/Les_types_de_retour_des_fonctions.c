//IV) Les types de retour des fonctions
// programme qui à l’aide d’une fonction compare(…) compare deux entiers fournis par l’utilisateur et qui retourne :
#include <stdio.h>

int compare_entiers(int entier1, int entier2)  // Fonction qui compare deux entiers
{
    if(entier1 == entier2)  // Si les deux entiers sont égaux
    {
        return 1; // Retourne 1
    }
    else  // Sinon
    {
        return 0; // Retourne 0
    }
}

char compare_entiers_caractere(int entier1, int entier2) // Fonction qui compare deux entiers et qui retourne V si les deux entiers sont égaux et F si les deux entiers ne sont pas égaux
{
    if(entier1 == entier2) // Si les deux entiers sont égaux
    {
        return 'V'; // Retourne V
    }
    else // Sinon
    {
        return 'F'; // Retourne F
    }
}

int compare_flottants(float flottant1, float flottant2) // Fonction qui compare deux flottants
{
    if(flottant1 == flottant2) // Si les deux flottants sont égaux
    {
        return 1; // Retourne 1
    }
    else // Sinon
    {
        return 0; // Retourne 0
    }
}

char compare_flottants_caractere(float flottant1, float flottant2) // Fonction qui compare deux flottants et qui retourne V si les deux flottants sont égaux et F si les deux flottants ne sont pas égaux
{
    if(flottant1 == flottant2) // Si les deux flottants sont égaux 
    {
        return 'V'; // Retourne V
    }
    else // Sinon
    {
        return 'F'; // Retourne F
    }
}

int main() 
{
    int entier1, entier2; // Déclaration des variables entier1 et entier2

    printf("Entrez deux entiers : ");// Demande à l'utilisateur de rentrer deux entiers
    scanf("%d %d", &entier1, &entier2); // Stocke les deux entiers dans les variables entier1 et entier2

    printf("La valeur de retour de la comparaison des entiers est : %d\n", compare_entiers(entier1, entier2)); // Affiche la valeur de retour de la comparaison des entiers
    printf("La valeur de retour de la comparaison des entiers sous forme de caractère est : %c\n", compare_entiers_caractere(entier1, entier2)); // Affiche la valeur de retour de la comparaison des entiers sous forme de caractère

    float flottant1, flottant2; // Déclaration des variables flottant1 et flottant2

    printf("Entrez deux flottants : "); // Demande à l'utilisateur de rentrer deux flottants
    scanf("%f %f", &flottant1, &flottant2); // Stocke les deux flottants dans les variables flottant1 et flottant2

    printf("La valeur de retour de la comparaison des flottants est : %d\n", compare_flottants(flottant1, flottant2)); // Affiche la valeur de retour de la comparaison des flottants
    printf("La valeur de retour de la comparaison des flottants sous forme de caractère est : %c\n", compare_flottants_caractere(flottant1, flottant2)); // Affiche la valeur de retour de la comparaison des flottants sous forme de caractère

    return 0;
}
