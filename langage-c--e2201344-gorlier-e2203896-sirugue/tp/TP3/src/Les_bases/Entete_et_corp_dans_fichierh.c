// II) Les bases
// Programme qui  affiche «Hello world » à l’aide d’une fonction affiche_hello() en définissant l’entête et le corps de la fonction dans un fichier fonction.h

// main.c
#include <stdio.h>
#include "fonction.h"

int main() // Main du programme
{
    printf(affiche_hello());
    return 0;
}