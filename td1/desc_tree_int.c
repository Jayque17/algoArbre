#include <stdio.h>

/* a.
       8
      / \
     3   9
    /\   /\
   2  7 4  6
  / \
 1   5

             4
            / \
           3   3
          /   / \
         4   5   2
        / \     / \
       5   1   1   6
      /   /
     2   3 

*/

typedef struct noeud{
    
    int val; /* étiquette */
    struct noeud* fg; /* fils gauche */
    struct noeud* fd; /* fils droit */

} Noeud, *Arbre;


/* b. */
void afficheArbrePositif(Noeud* A){

    Noeud* B = A;

    printf("%d", B->val);

    if(B->fg != NULL){

        return afficheArbrePositif(B->fg);

    }
    else{

        printf("%d", 0);
    }
    if(B->fd != NULL){

        return afficheArbrePositif(B->fd);
    }
    else{

        printf("%d", 0);
    }
}

/* c. */
/* d. */
int construitArbrePositif(Noeud** A){
    
}









