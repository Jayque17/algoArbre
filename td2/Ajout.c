#include <stdio.h>

typedef struct noeud{
    
    int val; /* étiquette */
    struct noeud *fg; /* fils gauche */
    struct noeud *fd; /* fils droit */

} Noeud, *Arbre;

/*
a.

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
*/

/* b. */

Noeud* initNode(int n){

    Noeud* node = NULL;
    node = (Noeud*) malloc(sizeof(Noeud));
    node->val = n;
    node->fg = NULL;
    node->fd = NULL;
    return node;
}

int ajout(Arbre *a, int n){

    Noeud** node = a;

    if(*node == NULL){

        *node = initNode(n);

        if(*node == NULL){

            return 0;
        }

        return 1;
    }

    else if((*node)->val == n){

        return 1;
    }

    else if((*node)->val > n){

        return ajout(&(*node)->fg, n);
    }

    return ajout(&(*node)->fd, n);
}