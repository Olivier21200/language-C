#include <stdio.h>

int temps_en_secondes(int heures, int minutes, int secondes) // Fonction qui convertit le temps en secondes
{
    int temps_total_en_secondes;
    temps_total_en_secondes = heures * 3600 + minutes * 60 + secondes;
    return temps_total_en_secondes;
}

int main() // Main du programme
{
    int heures, minutes, secondes; // Déclaration des variables heures, minutes et secondes

    printf("Entrez le temps en heures, minutes et secondes : "); // Demande à l'utilisateur de rentrer le temps en heures, minutes et secondes
    scanf("%d %d %d", &heures, &minutes, &secondes); // Stocke le temps en heures, minutes et secondes dans les variables heures, minutes et secondes

    int temps_en_sec = temps_en_secondes(heures, minutes, secondes);// Appel de la fonction temps_en_secondes
    printf("%d heures, %d minutes, %d secondes = %d secondes\n", heures, minutes, secondes, temps_en_sec);// Affiche le temps en heures, minutes et secondes et le temps en secondes
    
    return 0;
}
