#include <stdio.h>

/* Parcours en profondeur */
typedef struct noeud{
    
    int val; /* étiquette */
    struct noeud *fg; /* fils gauche */
    struct noeud *fd; /* fils droit */

} Noeud, *Arbre;

void OrdrePrefixe(Noeud* A){

    Noeud* B = A;

    printf("%d\n", B->val);

    if(B->fg != NULL){

        return OrdrePrefixe(B->fg);

    }
    if(B->fd != NULL){

        return OrdrePrefixe(B->fd);
    }
}

void OrdreInfixe(Noeud* A){

    Noeud* B = A;

    if(B->fg != NULL){

        return OrdreInfixe(B->fg);
    
    }

    printf("%d\n", B->val);

    if(B->fd != NULL){

        return OrdreInfixe(B->fd);
    }
}

void OrdreSuffixe(Noeud* A){

    Noeud* B = A;

    if(B->fg != NULL){

        return OrdreSuffixe(B->fg);
    }
    if(B->fd != NULL){

        return OrdreSuffice(B->fd);
    }

    printf("%d\n", B->val);
}

/* Definition une file : ???? */
/* Parcours en largeur */

/* table des péres */
/* noeud parent vers chq enfant */
/* noeud parent vers liste des enfants */