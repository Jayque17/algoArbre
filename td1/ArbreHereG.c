#include <stdio.h>

typedef struct noeud{
    
    int val; /* étiquette */
    struct noeud *fg; /* fils gauche */
    struct noeud *fd; /* fils droit */

} Noeud, *Arbre;

/* a.
      0
     / \
    0   0
   / \
  0   0

        0
       / \
      0   0
     /\   /\
    0  0 0  0
   / \
  0   0 

             0
            / \
           0   0
          / \
         0  0
        /\  /\
       0 0 0  0

        0
       / \
      0   0
     / \
    0   0
   / \
  0   0
 / \
0   0

*/

/* b. */

int estHG(Arbre a){

      Noeud* node = a;

      if(node->fd == NULL && node->fg == NULL){

            return 1;
      }
      else if(node->fd != NULL && node->fg == NULL){

            return 0;
      }
      else if(node->fd == NULL && node->fg != NULL){

            estHG(node->fg);
      }

      estHG(node->fd);
      estHG(node->fg);

}