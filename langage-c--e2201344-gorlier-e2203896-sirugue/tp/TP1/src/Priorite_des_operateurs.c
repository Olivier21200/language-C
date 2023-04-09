//IV ) Priorité des opérateurs
//Programme qui affiche les valeurs de X pour les différentes expressions suivantes :
#include <stdio.h>

int main() {
    //déclération de lavariable X
    int X;

    X = -3 + 4 * 5 - 6;
    printf("X = %d\n", X);

    X = (-3 + 4) * 5 - 6;
    printf("X = %d\n", X);

    X = -3 + (4 * 5) - 6;
    printf("X = %d\n", X);

    X = -3 + 4 * (5 - 6);
    printf("X = %d\n", X);

    return 0;
}

