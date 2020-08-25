#include <stdio.h>

typedef struct noeud{
    
    int val; /* étiquette */
    struct noeud *fg; /* fils gauche */
    struct noeud *fd; /* fils droit */

} Noeud, *Arbre;

/*

                        42
                        / \
                       18  45
                      / \    \
                    16  23    62
                   /      \
                  12       32
                 / \
                11  14
                    / 
                   13


                        42
                        / \
                       18  45
                      / \    
                    16  23    
                   /      \
                  12       32
                 / \
                11  14
                    / 
                   13


                        42
                        / \
                       18  45
                      / \    
                    12  23    
                   /  \   \
                  11   14  32
                      /
                     13

                        42
                        / \
                       23  45
                      / \    
                    12  32    
                   /  \   
                  11   14  
                      /
                     13
*/

Arbre extraitMin(Arbre* a){
    
    if(*a == NULL || (*a)->fg == NULL){

        Noeud** node = a;
        *a = NULL;
        return *node;
    }

    if((*a)->fg != NULL){

        return extraitMin((*a)->fg);
    }
}
/* Pour extraire la plus grande étiquete il faut utiliser fd au 
lieu de fg.*/

Arbre extrait(Arbre* a, int n){

    if(*a == NULL){

        return NULL;
    }

    if(n != (*a)->val){

        if(n < (*a)->val){

            return extrait((*a)->fg, n);
        }
        else if(n > (*a)->val){

            return extrait((*a)->fd, n);
        }
    }

    if((*a)->fg == NULL && (*a)->fd == NULL){

        Noeud** node = a;
        *a = NULL;
        return *node;
    }

    else if((*a)->fg != NULL && (*a)->fd == NULL){

        Noeud** node = a;
        *a = (*a)->fg;
        (*node)->fg = NULL;
        return *node;

    }

    else if((*a)->fg == NULL && (*a)->fd != NULL){

        Noeud** node = a;
        *a = (*a)->fd;
        (*node)->fd = NULL;
        return *node;
    }

    else if((*a)->fg != NULL && (*a)->fd != NULL){

        Noeud** node = a;
        *a = (*a)->fd;
        Noeud* minD = extraitMin(a);
        minD->fg = (*node)->fg;
        (*node)->fd = NULL;
        (*node)->fg = NULL;
        return *node;
    }
}
