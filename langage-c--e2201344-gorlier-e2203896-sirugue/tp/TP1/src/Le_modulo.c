//V) Le modulo
// Programme qui illustre les différences entre le modulo entier et le modulo de flottants
#include <stdio.h>

int main() {
    int x = 5 % 2; //modulo entier, retourne le reste de la division entière de 5 par 2
    printf("Valeur de la variable entière x = 5 % 2 : %d\n", x);

    
    float x2 = (int)5.0 % 2; //affiche une erreur car on ne peut pas faire de modulo avec des flottants avec l'opérateur %
    printf("Valeur de la variable flottante x : %f\n", x2);

    return 0;
}
