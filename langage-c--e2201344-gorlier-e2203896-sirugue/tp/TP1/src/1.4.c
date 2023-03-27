/*S’ouvrir au monde ! */
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

