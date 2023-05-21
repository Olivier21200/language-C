//IV) Les types de retour des fonctions
// programme qui à l’aide d’une fonction compare(…) compare deux entiers fournis par l’utilisateur et qui retourne :
#include <stdio.h>

int compare_entiers(int entier1, int entier2)
{
    // Pas de mesures de sécurité supplémentaires nécessaires pour les entiers
    if (entier1 == entier2) {
        return 1;
    } else {
        return 0;
    }
}

char compare_entiers_caractere(int entier1, int entier2)
{
    if (entier1 == entier2) {
        return 'V';
    } else {
        return 'F';
    }
}

int compare_flottants(float flottant1, float flottant2)
{
    // Utilisation d'une tolérance pour comparer les flottants
    float epsilon = 0.0001;
    if (fabs(flottant1 - flottant2) < epsilon) {
        return 1;
    } else {
        return 0;
    }
}

char compare_flottants_caractere(float flottant1, float flottant2)
{
    float epsilon = 0.0001;
    if (fabs(flottant1 - flottant2) < epsilon) {
        return 'V';
    } else {
        return 'F';
    }
}

int main()
{
    int entier1, entier2;

    printf("Entrez deux entiers : ");
    if (scanf("%d %d", &entier1, &entier2) != 2) {
        printf("Erreur : Entrée invalide.\n");
        return 1;
    }

    printf("La valeur de retour de la comparaison des entiers est : %d\n", compare_entiers(entier1, entier2));
    printf("La valeur de retour de la comparaison des entiers sous forme de caractère est : %c\n", compare_entiers_caractere(entier1, entier2));

    float flottant1, flottant2;

    printf("Entrez deux flottants : ");
    if (scanf("%f %f", &flottant1, &flottant2) != 2) {
        printf("Erreur : Entrée invalide.\n");
        return 1;
    }

    printf("La valeur de retour de la comparaison des flottants est : %d\n", compare_flottants(flottant1, flottant2));
    printf("La valeur de retour de la comparaison des flottants sous forme de caractère est : %c\n", compare_flottants_caractere(flottant1, flottant2));

    return 0;
}
