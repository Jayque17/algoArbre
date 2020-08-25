#include <stdio.h>

typedef struct noeud{
    
    int val; /* étiquette */
    struct noeud *fg; /* fils gauche */
    struct noeud *fd; /* fils droit */

} Noeud, *Arbre;

int Min(int a, int b){

    if(a < b){

        return a;
    }

    return b;
}

int estDeRecherche(Arbre a){

    if(a == NULL){

        return 1;
    }
    if(a->val < a->fg->val || a->val > a->fd->val){

        return 0;
    }

    return Min(estDeRecherche(a->fg), estDeRecherche(a->fd));
}