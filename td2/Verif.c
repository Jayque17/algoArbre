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

int CheckABR(Arbre a){

    Noeud* node = NULL;
    node = a;

    if(node == NULL){

        return 1;
    }
    
    if(node->fd == NULL && node->fg == NULL){

        return 1;
    }
    
    else if(node->fg->val > node->val || node->fd->val < node->val){

        return 0;
    }

    else if(node->fd->val > node->val && node->fg == NULL){
        
        return CheckABR(node->fd);
    }

    else if(node->fg->val < node->val && node->fd == NULL){

        return CheckABR(node->fg);
    }

    return Min(CheckABR(node->fd), CheckABR(node->fg));
}