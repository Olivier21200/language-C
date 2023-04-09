#include <stdio.h>

int temps_en_secondes(int heures, int minutes, int secondes) 
{
    int temps_total_en_secondes;
    temps_total_en_secondes = heures * 3600 + minutes * 60 + secondes;
    return temps_total_en_secondes;
}

int main() 
{
    int heures, minutes, secondes;
    printf("Entrez le temps en heures, minutes et secondes : ");
    scanf("%d %d %d", &heures, &minutes, &secondes);
    int temps_en_sec = temps_en_secondes(heures, minutes, secondes);
    printf("%d heures, %d minutes, %d secondes = %d secondes\n", heures, minutes, secondes, temps_en_sec);
    return 0;
}
