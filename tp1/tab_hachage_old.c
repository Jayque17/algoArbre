#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1

typedef struct celmot{
    char* mot;
    int nombre;
    struct celmot* suivant;
} CelluleM, *ListeM;


CelluleM* Allouecellule(char Mot[]){
    
    CelluleM* cel = (CelluleM*) malloc(sizeof(CelluleM));
    if(cel != NULL){
        (*cel).mot = Mot;
        (*cel).nombre = 1;
        (*cel).suivant = NULL;
    }
    return cel;
}

int AjouteListe(ListeM* L, char Mot[]){

    
    CelluleM** pt_to_cur_cell = L;
    CelluleM* cur_cell = *pt_to_cur_cell;

    
    
    while (cur_cell != NULL){
        int cmp_res = strcmp((*cur_cell).mot, Mot);
        
        if(cmp_res == 0){
            (*cur_cell).nombre += 1;
            return 1;
        }
        else if(cmp_res > 0){
            break;
        }
        pt_to_cur_cell = &(*cur_cell).suivant;
        cur_cell = *pt_to_cur_cell;
        /*cur_cell = (*cur_cell).suivant;*/
    }
    
    CelluleM* new_cell = Allouecellule(Mot);
    if(new_cell == NULL)
        return 0;
    *pt_to_cur_cell = new_cell;
    
    (*new_cell).suivant = cur_cell;
    return 1;
}

void AfficheListe(ListeM L){
    
    while(L != NULL){
        printf("%s %d\n", (*L).mot, (*L).nombre);
        L = (*L).suivant;
    }
}

void AfficheListebug(ListeM* L){
    
    ListeM* tmp = L;
    printf("%s %d\n", (**tmp).mot, (**tmp).nombre);

    while ((**tmp).suivant != NULL){

        *tmp = (**tmp).suivant;
        printf("%s %d\n", (**tmp).mot, (**tmp).nombre);
    }  
}

int RemoveList(ListeM* L, char Mot[]){
    
    CelluleM** pt_to_cur_cel = L;
    CelluleM* cur_cel = *pt_to_cur_cel;

    
    while(cur_cel != NULL){
        
        int cmp_res = strcmp((*cur_cel).mot, Mot);

        if(cmp_res == 0){
            if((*cur_cel).nombre == 1){
                *pt_to_cur_cel = (*cur_cel).suivant;
                free(cur_cel);
            }
            else{
                (*cur_cel).nombre -= 1;
            }
            
            return 1;
        }
        else if(cmp_res > 0){
            return 0;
        }

        pt_to_cur_cel = &(*cur_cel).suivant;
        cur_cel = (*cur_cel).suivant;
    }
    return 0;
}

unsigned int Hachage(char Mot[]){
    
    unsigned int sum = 0;
    for(int i = 0; i < strlen(Mot); ++i){
        sum += (i + 1) * Mot[i];
    }
    return sum % N;
}

int RechercheDico(ListeM T[], char Mot[]){

    ListeM* pt_t = &T[Hachage(Mot)];

    while((**pt_t).suivant != NULL){

        int res_cmp = strcmp((**pt_t).mot, Mot);

        if(res_cmp == 0){

            return (**pt_t).nombre;
        }
        else if(res_cmp > 0){

            return 0;
        }
        pt_t = &(**pt_t).suivant;
    }
    return 0;
}

int AjouteDico(ListeM T[], char Mot[]){

    ListeM L = NULL;
    T[Hachage(Mot)] = L;
    return AjouteListe(&L, Mot);
}

int NombreMot(ListeM T[]){

    
}


int main(int argc, char* argv[]){

    ListeM dico[N];
    FILE* file = NULL;
    
    file = fopen(argv[1], "r");

    char word[50] = "";
    
    while(feof(file) == 0){
        
        fscanf(file, "%s", word);
        AjouteDico(dico, word);
    }

    for(int i = 0; i < N; ++i){
        AfficheListe(dico[i]);
    }

    fclose(file);
    return 0;
}