//XII) Voyelle
// Programme qui compte le nombre de voyelles dans un texte saisi au clavier.
#include <stdio.h>
#include <string.h>

int main() 
{
    char texte[1000]; //On suppose que le texte ne contient pas plus de 1000 caractères
    int longueur, nb_voyelles = 0; //On initialise le nombre de voyelles à 0
    
    printf("Entrez un texte qui se termine par '#' : \n"); //On demande à l'utilisateur d'entrer un texte
    fgets(texte, 1000, stdin); //On récupère le texte saisi au clavier
    
    longueur = strlen(texte); //On récupère la longueur du texte
    
    for (int i = 0; i < longueur; i++)  //On parcourt le texte caractère par caractère
    {
        char c = texte[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' || 
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y') //On vérifie si le caractère est une voyelle
        {
            nb_voyelles++; //On incrémente le nombre de voyelles
        }
    }
    
    printf("Le texte contient %d voyelle(s).\n", nb_voyelles); //On affiche le nombre de voyelles
    
    return 0;
}
