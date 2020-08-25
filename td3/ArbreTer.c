#include <stdio.h>
/*
    a-------b---------------------t
    |       |                     |
    n       a---------i           r
    |       |         |           |
    i   r---v   e-----l      i----u
    |   |   |   |     |      |    |
    m   0   a-e r     l      c    c
    |       | | |     |      |    |
    a       r t e     a      h    0
    |       | |       |      |
    l       d t       r      e
    |       | |       |      |
    0       0 e       d      0
              |       |
              0       0
*/


typedef struct noeud{

    char lettre;        /* étiquette */
    struct noeud *fg;    /* fils gauche */
    struct noeud *fd;    /* fils droit */
    struct noeud *fils;  /* fils principal */

} Tnoeud, *Tarbre;

int recherche(Tarbre a, char* m){

    Tnoeud* node = a;

    for(int i = 0; i < sizeof(m) + 1; ++i){

        if(node == NULL){

            return 0;
        }

        if(m[i] < node->lettre){

            node = node->fg;
        }

        else if(m[i] == node->lettre){

            node = node->fils;
        }

        else if(m[i] > node->lettre){

            node = node->fd;
        }
    }

    return 1;
}

int nombreMot(Tarbre a){

    if(a == NULL){

        return 0;
    }

    if(a->lettre == 0){

        return 1 + nombreMot(a->fg) + nombreMot(a->fils) + nombreMot(a->fd);
    }
    else{

        return nombreMot(a->fg) + nombreMot(a->fils) + nombreMot(a->fd);
    }
}

Tarbre AlloueTnoeud(char c){

    Tnoeud* node = NULL;
    node = (Tnoeud*) malloc(sizeof(Tnoeud));
    return node;
}

/* TODO int ajouterMot(Tarbre* a, char* m) */