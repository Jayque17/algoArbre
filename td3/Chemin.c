#include <stdio.h>

#define MAX 10

typedef struct noeud{
    
    int val;            /* étiquette */
    struct noeud *fg;   /* fils gauche */
    struct noeud *fd;   /* fils droit */

} Noeud, *Arbre;


void afficheCheminAux(Arbre a, int buffer[], int indice){

    if(a != NULL){

        buffer[indice] = a->val;
        afficheCheminAux(a->fg, buffer, indice + 1);
        afficheCheminAux(a->fd, buffer, indice + 1);
    }

    else{

        for(int i = 0; i < indice; ++i){

            printf("%d ", buffer[i]);
        }

        printf("\n");
    }
}

void afficheChemin(Arbre T){

    int buffer[MAX];
    int indice = 0;
    afficheCheminAux(T, buffer, indice);
}