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
        printf("Aucune personne enregistrée.\n");
        return;
    }
    printf("Liste des personnes enregistrées :\n");
    Personne *p = liste_personnes;
    while (p != NULL) {
        printf("Nom : %s\n", p->nom);
        printf("Prenom : %s\n", p->prenom);
        printf("Badge : %d\n", p->badge);
        printf("Code secret : %s\n", p->code_secret);
        printf("Dernière visite : %s\n", ctime(&p->derniere_visite));
        p = p->suivant;
    }
}

// Fonction pour ajouter une personne à la liste
void ajouter_personne() 
{
    Personne *nouvelle_personne = malloc(sizeof(Personne));
    if (nouvelle_personne == NULL) {
        printf("Erreur : impossible d'allouer de la mémoire.\n");
        return;
    }
    printf("Nom : ");
    fgets(nouvelle_personne->nom, sizeof(nouvelle_personne->nom), stdin);
    nouvelle_personne->nom[strcspn(nouvelle_personne->nom, "\n")] = '\0'; // Supprimer le caractère de nouvelle ligne
    printf("Prénom : ");
    fgets(nouvelle_personne->prenom, sizeof(nouvelle_personne->prenom), stdin);
    nouvelle_personne->prenom[strcspn(nouvelle_personne->prenom, "\n")] = '\0'; // Supprimer le caractère de nouvelle ligne
    printf("Badge (4 chiffres) : ");
    scanf("%d", &nouvelle_personne->badge);
    getchar(); // Consommer le caractère de nouvelle ligne restant dans le buffer d'entrée
    printf("Code secret : ");
    fgets(nouvelle_personne->code_secret, sizeof(nouvelle_personne->code_secret), stdin);
    nouvelle_personne->code_secret[strcspn(nouvelle_personne->code_secret, "\n")] = '\0'; // Supprimer le caractère de nouvelle ligne
    nouvelle_personne->derniere_visite = 0;
    nouvelle_personne->suivant = liste_personnes;
    nouvelle_personne->precedent = NULL;
    if (liste_personnes != NULL) {
        liste_personnes->precedent = nouvelle_personne;
    }
    liste_personnes = nouvelle_personne;
    printf("Personne ajoutée avec succès.\n");
}


void supprimer_personne() {
    int badge;
    printf("Badge de la personne à supprimer : ");
    scanf("%d", &badge);
    getchar(); // Consommer le caractère de nouvelle ligne restant dans le buffer d'entrée
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
    printf("Personne supprimée avec succès.\n");
}


// Fonction pour modifier le code secret d'une personne
void modifier_code_secret() 
{
    int badge;
    printf("Badge de la personne dont on veut modifier le code secret : ");
    scanf("%d", &badge); // Demande à l'utilisateur d'entrer le numéro de badge
    getchar(); // Consomme le caractère de nouvelle ligne restant dans le buffer d'entrée
    
    Personne *p = liste_personnes;
    while (p != NULL && p->badge != badge) {
        p = p->suivant;
    }
    if (p == NULL) {
        printf("Aucune personne ne correspond au badge %d.\n", badge);
        return;
    }

    printf("Nouveau code secret : ");
    fgets(p->code_secret, MAX_CODE_SECRET, stdin); // Utilise fgets pour lire le code secret depuis l'entrée utilisateur
    p->code_secret[strcspn(p->code_secret, "\n")] = '\0'; // Supprime le caractère de nouvelle ligne à la fin du code secret

    printf("Code secret modifie avec succes.\n");
}


// Programmer une fonction permettant de sauvegarder la liste de personnes dans un fichier.
void sauvegarder_liste() 
{
    FILE *fichier = fopen("personnes.txt", "w"); // Ouvre le fichier en mode écriture
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier.\n");
        return;
    }
    Personne *p = liste_personnes;
    while (p != NULL) {
        fprintf(fichier, "%s %s %d %s %ld ", p->nom, p->prenom, p->badge, p->code_secret, p->derniere_visite); // Écrit les informations de la personne dans le fichier
        p = p->suivant;
    }
    fclose(fichier); // Ferme le fichier
    printf("Liste sauvegardee avec succes.\n");
}


// Écrire une fonction qui permet de lire un fichier contenant une liste de personnes et
// de stocker ces informations dans une liste doublement chaînée pouvant être
// manipulée par les fonctions précédemment écrites.
void charger_liste() 
{
    FILE *fichier = fopen("personnes.txt", "r"); // Ouvre le fichier en mode lecture
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier.\n");
        return;
    }
    Personne *p = liste_personnes;
    while (p != NULL) {
        fscanf(fichier, "%s %s %d %s %ld ", p->nom, p->prenom, &p->badge, p->code_secret, &p->derniere_visite); // Lit les informations depuis le fichier et les stocke dans la liste
        p = p->suivant;
    }
    fclose(fichier); // Ferme le fichier
    printf("Liste chargee avec succes.\n");
}


// 5) Simuler le contrôle d’accès via le clavier :
// - saisir le numéro de badge.
// - demander le code secret correspondant au badge.
// - suivant le code secret :
//   * Afficher le nom de la personne et inscrire la date et l’heure de la visite.
//   * Afficher "Accès refusé".

int main() 
{
    int choix;
    do {
        // Affichage du menu
        printf("1. Afficher la liste des personnes enregistrees dans le fichier.\n");
        printf("2. Ajouter une personne.\n");
        printf("3. Supprimer une personne.\n");
        printf("4. Modifier le code secret d'une personne.\n");
        printf("5. Sauvegarder la liste de personnes dans un fichier.\n");
        printf("6. Charger une liste de personnes depuis un fichier.\n");
        printf("7. Simuler le contrôle d'accès.\n");
        printf("8. Quitter.\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        
        switch (choix) {
            case 1:
                afficher_liste(); // Appel de la fonction pour afficher la liste des personnes
                break;
            case 2:
                ajouter_personne(); // Appel de la fonction pour ajouter une personne
                break;
            case 3:
                supprimer_personne(); // Appel de la fonction pour supprimer une personne
                break;
            case 4:
                modifier_code_secret(); // Appel de la fonction pour modifier le code secret d'une personne
                break;
            case 5:
                sauvegarder_liste(); // Appel de la fonction pour sauvegarder la liste dans un fichier
                break;
            case 6:
                charger_liste(); // Appel de la fonction pour charger la liste depuis un fichier
                break;
            case 7:
                // Simulation du contrôle d'accès
                int badge;
                printf("Numéro de badge : ");
                scanf("%d", &badge);
                Personne *p = liste_personnes;
                while (p != NULL && p->badge != badge) {
                    p = p->suivant;
                }
                if (p != NULL) {
                    char code_secret[MAX_CODE_SECRET];
                    printf("Code secret : ");
                    scanf("%s", code_secret);
                    if (strcmp(p->code_secret, code_secret) == 0) {
                        printf("Accès autorisé.\n");
                        time_t now = time(NULL);
                        p->derniere_visite = now;
                        printf("Nom : %s\n", p->nom);
                        printf("Date et heure de la visite : %s", ctime(&now));
                    } else {
                        printf("Accès refusé.\n");
                    }
                } else {
                    printf("Aucune personne ne correspond au badge %d.\n", badge);
                }
                break;
            case 8:
                printf("Au revoir.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 8);

    return 0;
}


    


