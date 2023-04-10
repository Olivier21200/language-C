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

//Tableau Varibale global de 20 personnes
struct PERSONNE Tableau_personnes[20];

//Fonction qui retourne le nombre de personnes dans le tableau
int nb_personnes(struct PERSONNE personnes[])
{
    int i = 0;
    while (personnes[i].nom[0] != '\0')
    {
        i++;
    }
    return i;
}

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

    //regarde le nombre de personne dans le tableau
    int nb = nb_personnes(Tableau_personnes);
    //ajoute la personne au tableau
    Tableau_personnes[nb] = *personne;

}


//Fonction qui affichage les données relatives à une personne.
void afficher_personne(struct PERSONNE personne)
{
    printf("Nom : %s Prenom : %s Date de naissance : %d/%d/%d \n", personne.nom, personne.prenom, personne.date_naissance.jour, personne.date_naissance.mois, personne.date_naissance.annee);
}

//Fonction qui affichage l'ensemble des personnes du tableau.
void afficher_personnes()
{
    int i;
    for (i = 0; i < nb_personnes(Tableau_personnes); i++)
    {
        afficher_personne(Tableau_personnes[i]);

    }
}

//Fonction qui classe les noms par date de naissance.
void trier_par_date_naissance(struct PERSONNE personnes[], int nb_personnes)
{
    int i, j;
    struct PERSONNE temp;
    for (i = 0; i < nb_personnes; i++)
    {
        for (j = i + 1; j < nb_personnes; j++)
        {
            if (personnes[i].date_naissance.annee > personnes[j].date_naissance.annee)
            {
                temp = personnes[i];
                personnes[i] = personnes[j];
                personnes[j] = temp;
            }
            else if (personnes[i].date_naissance.annee == personnes[j].date_naissance.annee)
            {
                if (personnes[i].date_naissance.mois > personnes[j].date_naissance.mois)
                {
                    temp = personnes[i];
                    personnes[i] = personnes[j];
                    personnes[j] = temp;
                }
                else if (personnes[i].date_naissance.mois == personnes[j].date_naissance.mois)
                {
                    if (personnes[i].date_naissance.jour > personnes[j].date_naissance.jour)
                    {
                        temp = personnes[i];
                        personnes[i] = personnes[j];
                        personnes[j] = temp;
                    }
                }
            }
        }
    }
}

//Fonction qui permettant de retrouver, modifier et afficher les données relatives à une personne à partir de son nom.
void modifier_personne(char nom_personne[20])
{
    int i;
    for (i = 0; i < nb_personnes(Tableau_personnes); i++)
    {
        if (strcmp(Tableau_personnes[i].nom, nom_personne) == 0)
        {   
            printf("Données actuel de la personne : \n");
            afficher_personne(Tableau_personnes[i]);
            
            printf("Voulez vous modifier les données de cette personne ? (O/N) \n");
            char reponse;
            scanf("%c", &reponse);
            getchar();
            switch(reponse)
            {
                case 'O':
                    definir_personne(&Tableau_personnes[i]);
                    afficher_personne(Tableau_personnes[i]);
                    break;
                case 'N':
                    print ("Données non modifiées");
                    break;
            }
            definir_personne(&Tableau_personnes[i]);
            afficher_personne(Tableau_personnes[i]);
        }
    }
}


//Fonction qui permet de supprimer une personne dans le tableau.
void supprimer_personne(struct PERSONNE personne)
{
    int i;
    for(i = 0; i < nb_personnes(Tableau_personnes); i++)
    {
        if(strcmp(Tableau_personnes[i].nom, personne.nom) == 0)
        {
            Tableau_personnes[i] = Tableau_personnes[nb_personnes(Tableau_personnes) - 1];
            Tableau_personnes[nb_personnes(Tableau_personnes) - 1] = personne;
        }
    }
}


//Menu principal qui propose des action  en fonction des chois de l'utilisateur et qui permet de quitter le programme et qui test l'ensemble des fonction.
int main()
{
    int choix;
    struct PERSONNE personne;
    char nom_personne[20];
    do // Boucle principale du menu
    {
        printf("1. Ajouter une personne \n");
        printf("2. Afficher les personnes \n");
        printf("3. Modifier une personne \n");
        printf("4. Supprimer une personne \n");
        printf("5. Quitter \n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        getchar();
        switch (choix)
        {
            case 1: // Ajouter une personne
                definir_personne(&personne);
                break;
            case 2: // Afficher les personnes
                afficher_personnes();
                break;
            case 3: // Modifier une personne
                printf("Entrez le nom de la personne à modifier : ");
                fgets(nom_personne, sizeof(nom_personne), stdin);
                nom_personne[strcspn(nom_personne, "\n")] = '\0';
                modifier_personne(nom_personne);
                break;
            case 4: // Supprimer une personne
                printf("Entrez le nom de la personne à supprimer : ");
                fgets(nom_personne, sizeof(nom_personne), stdin);
                nom_personne[strcspn(nom_personne, "\n")] = '\0';
                supprimer_personne(personne);
                break;
            case 5: // Quitter
                printf("Au revoir ! \n");
                break;
            default: // Choix incorrect
                printf("Choix incorrect ! \n");
                break;
        }
    } while (choix != 5); // Tant que l'utilisateur ne choisit pas 5, on reste dans le menu principal
    return 0;
}