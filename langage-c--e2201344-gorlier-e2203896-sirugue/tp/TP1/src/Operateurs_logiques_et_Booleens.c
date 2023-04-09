//VI) Opérateurs logiques et Booléens
//Programme qui illustre les opérateurs logiques et booléens en C
#include <stdio.h>
#include <stdbool.h>

int main() {
    int a = 5;
    int b = 6;
    bool res_et_binaire = 0;

    res_et_binaire = a & b;  // vrai (différent de 0)
    printf("Résultat de a & b en binaire : %d\n", res_et_binaire);
    //Opérateur ET bit à bit" sur les nombres binaires de "a" et "b".

    bool res_et_logique2 = a && b;  // vrai (différent de 0)
    printf("Résultat de a && b en booléen : %d\n", res_et_logique2);
    //Oeffectue une opération de ET logique entre les valeurs de "a" et "b".

    bool res_ou_binaire3 = a | b;  // vrai (différent de 0)
    printf("Résultat de a | b en binaire : %d\n", res_ou_binaire3);
    //opérateur logique "a|b" effectue une opération de OU inclusif bit à bit entre les valeurs de "a" et "b"".

    bool res_ou_logique4 = a || b;  // vrai (différent de 0)
    printf("Résultat de a || b en booléen : %d\n", res_ou_logique4);
    //L'opérateur logique "a||b" en C donne 1 si au moins l'une des deux valeurs est différente de 0. 
    //Il évalue d'abord la valeur de "a" et si elle est différente de 0, le résultat est immédiatement 1.
    

    bool res_ou_exclusif5 = a ^ b;  // vrai (différent de 0)
    printf("Résultat de a ^ b en binaire : %d\n", res_ou_exclusif5);
    //effectue une opération de OU exclusif bit à bit entre les valeurs de "a" et "b".

    bool res_non_binaire5 = ~a;  // faux (égal à 0)
    printf("Résultat de ~a en binaire : %d\n", res_non_binaire5);
    //effectue une opération de complément à un bit sur l'opérande.

    bool res_non_logique6 = !a;  // faux (égal à 0)
    printf("Résultat de !a en booléen : %d\n", res_non_logique6);
    //effectue une opération de négation logique sur l'opérande
    
    return 0;
}
