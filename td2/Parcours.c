#include <stdio.h>

typedef struct noeud{
    
    int val; /* étiquette */
    struct noeud *fg; /* fils gauche */
    struct noeud *fd; /* fils droit */

} Noeud, *Arbre;

/* 
Arbre binaire de recherche def :
Pour chaque noeud le noeud inferieur gauche contient une valeur 
inférieur.
Le noeud inférieur droit contient une valeur supérieur.

a.
L'arbre 1 est un ABR.
L'arbre 2 est un ABR.

1 prefixe : 20 13 8 7 11 23 21 27
1 suffixe : 7 11 8 13 21 27 23 20
1 infixe :  7 8 11 13 20 21 23 27
2 prefixe : 24 16 11 10 14 29 25 23 26 31
2 suffixe : 10 14 11 16 23 26 25 31 29 24
2 infixe : 10 11 14 16 24 23 25 26 29 31
*/

Arbre Recherche(Arbre a, int n){

    Noeud* node = a;

    if(node == NULL){

        return NULL;
    }

    if(n == node->val){

        return node;
    }
    else if(n > node->val){

        return Recherche(node->fd, n);
    }

    return Recherche(node->fg, n);
}