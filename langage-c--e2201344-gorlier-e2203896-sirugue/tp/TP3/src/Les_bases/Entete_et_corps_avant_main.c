// II) Les bases
// Programme qui  affiche «Hello world » à l’aide d’une fonction affiche_hello() en définissant l’entête et le corps de la fonction avant le main
#include <stdio.h>

void affiche_hello(); // déclaration de la fonction (Entete de la fonction)

void affiche_hello() // corps de la fonction
{
    printf("Hello world\n");
}

int main() // Main du programme
{
    affiche_hello();
    return 0;
}


