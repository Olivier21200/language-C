#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NOM 50
#define MAX_PRENOM 50
#define MAX_CODE_SECRET 10

typedef struct personne {
    char nom[MAX_NOM];
    char prenom[MAX_PRENOM];
    int badge;
    char code_secret[MAX_CODE_SECRET];
    time_t derniere_visite;
    struct personne *suivant;
    struct personne *precedent;
} Personne;

Personne *liste_personnes = NULL;

// Fonction pour afficher la liste des personnes enregistrées
void afficher_liste() {
    if (liste_personnes == NULL) {
        printf("Aucune personne enregistree.\n");
        return;
    }
    printf("Liste des personnes enregistrees :\n");
    Personne *p = liste_personnes;
    while (p != NULL) {
        printf("Nom : %s\n", p->nom);
        printf("Prenom : %s\n", p->prenom);
        printf("Badge : %d\n", p->badge);
        printf("Code secret : %s\n", p->code_secret);
        printf("Derniere visite : %s\n", ctime(&p->derniere_visite));
        p = p->suivant;
    }
}

// Fonction pour ajouter une personne à la liste
void ajouter_personne() 
{
    Personne *nouvelle_personne = malloc(sizeof(Personne));
    if (nouvelle_personne == NULL) {
        printf("Erreur : impossible d'allouer de la memoire.\n");
        return;
    }
    printf("Nom : ");
    scanf("%s", nouvelle_personne->nom);
    printf("Prenom : ");
    scanf("%s", nouvelle_personne->prenom);
    printf("Badge (4 chiffres) : ");
    scanf("%d", &nouvelle_personne->badge);
    printf("Code secret : ");
    scanf("%s", nouvelle_personne->code_secret);
    nouvelle_personne->derniere_visite = 0;
    nouvelle_personne->suivant = liste_personnes;
    nouvelle_personne->precedent = NULL;
    if (liste_personnes != NULL) {
        liste_personnes->precedent = nouvelle_personne;
    }
    liste_personnes = nouvelle_personne;
    printf("Personne ajoutee avec succes.\n");
}

// Fonction pour supprimer une personne suivant le numéro de badge
void supprimer_personne() {
    int badge;
    printf("Badge de la personne a supprimer : ");
    scanf("%d", &badge);
    Personne *p = liste_personnes;
    while (p != NULL && p->badge != badge) {
        p = p->suivant;
    }
    if (p == NULL) {
        printf("Aucune personne ne correspond au badge %d.\n", badge);
        return;
    }
    if (p->precedent != NULL) {
        p->precedent->suivant = p->suivant;
    } else {
        liste_personnes = p->suivant;
    }
    if (p->suivant != NULL) {
        p->suivant->precedent = p->precedent;
    }
    free(p);
    printf("Personne supprimee avec succes.\n");
}

// Fonction pour modifier le code secret d'une personne
void modifier_code_secret() 
{
    int badge;
    printf("Badge de la personne dont on veut modifier le code secret : ");
    scanf("%d", &badge);
    Personne *p = liste_personnes;
    while (p != NULL && p->badge != badge) {
        p = p->suivant;
    }
    if (p == NULL) {
        printf("Aucune personne ne correspond au badge %d.\n", badge);
        return;
    }
}

//Programmer une fonction permettant de sauvegarder la liste de personnes dans un fichier.
void sauvegarder_liste() 
{
    FILE *fichier = fopen("personnes.txt", "w");
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier.\n");
        return;
    }
    Personne *p = liste_personnes;
    while (p != NULL) {
        fprintf(fichier, "%s %s %d %s %ld ", p->nom, p->prenom, p->badge, p->code_secret, p->derniere_visite);
        p = p->suivant;
    }
    fclose(fichier);
    printf("Liste sauvegardee avec succes.\n");
}

//Écrire une fonction qui permet de lire un fichier contenant une liste de personnes et
//de stocker ces informations dans une liste doublement chainée pouvant être
//manipulée par les fonctions précédemment écrites.
void charger_liste() 
{
    FILE *fichier = fopen("personnes.txt", "r");
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier.\n");
        return;
    }
    Personne *p = liste_personnes;
    while (p != NULL) {
        fscanf(fichier, "%s %s %d %s %ld ", p->nom, p->prenom, &p->badge, p->code_secret, &p->derniere_visite);
        p = p->suivant;
    }
    fclose(fichier);
    printf("Liste chargee avec succes.\n");
}

//5) Simuler le contrôle d’accès via le clavier :
//- saisir le numéro de badge.
//- demander le code secret correspondant au badge.
//- suivant le code secret :
//*Afficher le nom de la personne et inscrire la date et l’heure de la visite.
//*Afficher accès refusé
int main() 
{
    int choix;
    do {
        printf("1. Afficher la liste des personnes enregistrees dans le fichier.\n");
        printf("2. Ajouter une personne.\n");
        printf("3. Supprimer une personne.\n");
        printf("4. Modifier le code secret d'une personne.\n");
        printf("5. Sauvegarder la liste de personnes dans un fichier.\n");
        printf("6. Charger une liste de personnes depuis un fichier.\n");
        printf("7. Quitter.\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                afficher_liste();
                break;
            case 2:
                ajouter_personne();
                break;
            case 3:
                supprimer_personne();
                break;
            case 4:
                modifier_code_secret();
                break;
            case 5:
                sauvegarder_liste();
                break;
            case 6:
                charger_liste();
                break;
            case 7:
                printf("Au revoir.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 7);
    return 0;
}

    


