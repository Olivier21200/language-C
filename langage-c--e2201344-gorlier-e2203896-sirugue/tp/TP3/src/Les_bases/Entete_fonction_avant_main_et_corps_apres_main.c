// II) Les bases
// Programme Définissant l’entête de la fonction avant le main et le corps de la fonction après le main et qui affiche «Hello world » à l’aide d’une fonction affiche_hello()
#include <stdio.h>

void affiche_hello(); // déclaration de la fonction (Entete de la fonction)

int main() // Main du programme
{
    affiche_hello();
    return 0;
}

void affiche_hello() // corps de la fonction
{
    printf("Hello world\n");
}

