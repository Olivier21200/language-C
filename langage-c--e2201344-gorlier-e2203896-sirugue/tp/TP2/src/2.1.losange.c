#include <stdio.h>

int main()
{
    int c, j=0, s, ligne;
  
    printf("Entrez le nombre de lignes: ");
    scanf("%d",&ligne);
  
    for(c=1; c<=ligne; ++c, j=0)
    {
        for(s=1; s<=ligne-c; ++s)
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