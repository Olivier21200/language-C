#include <stdio.h>

int temps_en_secondes(int heures, int minutes, int secondes)
{
    int temps_total_en_secondes;

    // Vérification des limites des entrées utilisateur
    if (heures < 0 || minutes < 0 || secondes < 0) {
        printf("Erreur : Les valeurs doivent être positives.\n");
        return -1;
    }

    // Prévention des débordements de pile en limitant les valeurs des heures, minutes et secondes
    if (heures > 23 || minutes > 59 || secondes > 59) {
        printf("Erreur : Les valeurs des heures, minutes et secondes doivent respecter les limites de temps.\n");
        return -1;
    }

    temps_total_en_secondes = heures * 3600 + minutes * 60 + secondes;
    return temps_total_en_secondes;
}

int main()
{
    int heures, minutes, secondes;

    printf("Entrez le temps en heures, minutes et secondes : ");
    // Utilisation de scanf avec une spécification de format sécurisée pour éviter les attaques par injection
    if (scanf("%d %d %d", &heures, &minutes, &secondes) != 3) {
        printf("Erreur : Entrée invalide.\n");
        return 1;
    }

    int temps_en_sec = temps_en_secondes(heures, minutes, secondes);
    if (temps_en_sec == -1) {
        // Gestion des erreurs de conversion des valeurs de temps en secondes
        return 1;
    }

    printf("%d heures, %d minutes, %d secondes = %d secondes\n", heures, minutes, secondes, temps_en_sec);

    return 0;
}
