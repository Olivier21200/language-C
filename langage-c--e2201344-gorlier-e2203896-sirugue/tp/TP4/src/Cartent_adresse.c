#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Le premier est le pointeur vers la chaîne de caractères où stocker l'entrée, 
//le deuxième est la taille maximale de la chaîne de caractères à lire 
//(pour éviter les débordements de tampon) et le troisième est le flux d'entrée 
//(dans notre cas stdin pour l'entrée standard).

struct DATE // Déclaration de la structure DATE
{
    int jour;
    int mois;
    int annee;
};

struct PERSONNE // Déclaration de la structure PERSONNE
{
    char nom[20];
    char prenom[20];
    struct DATE date_naissance;
};

//Fonction qui permet de définir une personne en entrant ses caractéristiques au clavier.
void definir_personne(struct PERSONNE *personne)
{
    printf("Entrez le nom : ");
    fgets(personne->nom, sizeof(personne->nom), stdin); // fgets() permet de récupérer une chaîne de caractères au clavier
    personne->nom[strcspn(personne->nom, "\n")] = '\0'; // Supprime le caractère '\n' à la fin de la chaîne de caractères

    printf("Entrez le prénom : ");
    fgets(personne->prenom, sizeof(personne->prenom), stdin);
    personne->prenom[strcspn(personne->prenom, "\n")] = '\0'; // Supprime le caractère '\n' à la fin de la chaîne de caractères

    printf("Entrez la date de naissance (jour mois année) : ");
    scanf("%d %d %d", &personne->date_naissance.jour, &personne->date_naissance.mois, &personne->date_naissance.annee);
    getchar(); // Consomme le caractère '\n' laissé dans le flux d'entrée stdin par la fonction scanf()
}


int main()
{
    struct PERSONNE personne1; // Déclaration d'une variable de type PERSONNE
    definir_personne(&personne1); // Appel de la fonction definir_personne() avec l'adresse de la variable personne1 pour définir les caractéristiques de la personne1
    return 0;
}