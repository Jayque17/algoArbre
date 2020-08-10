#include <stdio.h>

typedef struct noeud{
    
    int val; /* étiquette */
    struct noeud *fg; /* fils gauche */
    struct noeud *fd; /* fils droit */

} Noeud, *Arbre;



int Hauteur(Noeud* A){

    Noeud* B = A;

    if(B == NULL){
        
        return -1;
    }
    else if(B->fd == NULL && B->fg == NULL){
        
        return 1;
    }
    else if(B->fd != NULL && B->fg == NULL){

        return 1 + Hauteur(B->fd);
    }
    else if(B->fd == NULL && B->fg != NULL){
       
        return 1 + Hauteur(B->fg);
    }

    return 1 + Max(Hauteur(B->fg), Hauteur(B->fd));
}

int NombreNoeud(Noeud* A){

    Noeud* B = A;

    if(B == NULL){
        
        return 0;
    }
    else if(B->fd == NULL && B->fg == NULL){
        
        return 1;
    }
    else if(B->fd != NULL && B->fg == NULL){

        return 1 + NombreNoeud(B->fd);
    }
    else if(B->fd == NULL && B->fg != NULL){
       
        return 1 + NombreNoeud(B->fg);
    }

    return 1 + NombreNoeud(B->fg) + NombreNoeud(B->fd);
}

int NombreNoeudInterne(Noeud* A){

    Noeud* B = A;

    if(B == NULL){
        
        return 0;
    }
    else if(B->fd == NULL && B->fg == NULL){
        
        return 0;
    }
    else if(B->fd != NULL && B->fg == NULL){

        return 1 + NombreNoeudInterne(B->fd);
    }
    else if(B->fd == NULL && B->fg != NULL){
       
        return 1 + NombreNoeudInterne(B->fg);
    }

    return 1 + NombreNoeudInterne(B->fg) + NombreNoeudInterne(B->fd);
}

int NombreFeuille(Noeud* A){

    Noeud* B = A;

    if(B == NULL){
        
        return 0;
    }
    else if(B->fd == NULL && B->fg == NULL){
        
        return 1;
    }
    else if(B->fd != NULL && B->fg == NULL){

        return NombreNoeud(B->fd);
    }
    else if(B->fd == NULL && B->fg != NULL){
       
        return NombreNoeud(B->fg);
    }

    return NombreNoeud(B->fg) + NombreNoeud(B->fd);
}

int NombreNoeud2Fils(Noeud* A){

    Noeud* B = A;

    if(B == NULL){
        
        return 0;
    }
    else if(B->fd == NULL && B->fg == NULL){
        
        return 0;
    }
    else if(B->fd != NULL && B->fg == NULL){

        return NombreNoeud(B->fd);
    }
    else if(B->fd == NULL && B->fg != NULL){
       
        return NombreNoeud(B->fg);
    }

    return 1 + NombreNoeud(B->fg) + NombreNoeud(B->fd);
}