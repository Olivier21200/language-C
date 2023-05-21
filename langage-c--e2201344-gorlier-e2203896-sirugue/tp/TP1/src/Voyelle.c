//XII) Voyelle
// Programme qui compte le nombre de voyelles dans un texte saisi au clavier.
#include <stdio.h>
#include <string.h>

int main() 
{
    char texte[1000];
    int longueur, nb_voyelles = 0;
    
    printf("Entrez un texte qui se termine par '#' : \n");
    
    // Lecture sécurisée du texte avec fgets
    if (fgets(texte, sizeof(texte), stdin) == NULL)
    {
        printf("Erreur de lecture.\n");
        return 1;
    }
    
    // Suppression du caractère '\n' en fin de chaîne
    texte[strcspn(texte, "\n")] = '\0';
    
    longueur = strlen(texte);
    
    for (int i = 0; i < longueur; i++)
    {
        char c = texte[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' || 
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
        {
            nb_voyelles++;
        }
    }
    
    printf("Le texte contient %d voyelle(s).\n", nb_voyelles);
    
    return 0;
}

