#include<stdio.h>
 
int main()
{
    int i, j, ligne;
  //Affichage du carée
  printf("Entrez le nombre de lignes pour le carée: ");
  scanf("%d",&ligne);
  printf("\n");
     
    for(i=0; i < ligne; i++)
    {
        for(j=0; j < ligne; j++)
    {
           printf("*");
        }
        printf("\n");
    }

    //Affichage du triangle isocèle non perpendiculaire à gauche
    printf("\n");
    int a = 0;

    printf("Entrez un entier n pour le triangle issocèle à gauche : ");
    scanf("%d", &a);

    // Affichage de la partie supérieure du triangle inversé
    for (i = 1; i <= a; i++) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Affichage de la partie inférieure du triangle inversé
    for (i = a-1; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    //Affichage du triangle isocèle non perpendiculaire à droite
    printf("\n");
     int b=0;

    printf("Entrez un entier b : ");
    scanf("%d", &b);

    // Affichage du triangle sur le côté droit
    for (i = 1; i <= b; i++) {
        for (j = 1; j <= b-i; j++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    int c, z, s, ligne2;
  
    printf("Entrez le nombre de lignes: ");
    scanf("%d",&ligne2);
  
    for(c=1; c<=ligne2; ++c, z=0)
    {
        for(s=1; s<=ligne2-c; ++s)
        {
            printf("  ");
        }
        while(j != 2*c-1)
        {
            printf("* ");
            ++j;
        }
        printf("\n");
    }




















    return 0;
}