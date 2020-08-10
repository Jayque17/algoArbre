#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 2



typedef struct celmot{
    
    char* mot;
    int nombre;
    struct celmot* suivant;

} CelluleM, *ListeM;



CelluleM* Allouecellule(char Mot[]){
    
    CelluleM* cel = (CelluleM*) malloc(sizeof(CelluleM));
    if(cel != NULL){
        (*cel).mot = (char*)malloc((strlen(Mot) + 1) * sizeof(char));
        strcpy((*cel).mot, Mot);
        (*cel).nombre = 1;
        (*cel).suivant = NULL;
    }
    return cel;
}

void DestroyCell(CelluleM* cell){

    free(cell->mot);
    free(cell);
}

void AfficheListe(ListeM L){
    
    printf("\n");

    while(L != NULL){
    
        printf("%s %d\n", (*L).mot, (*L).nombre);
        L = (*L).suivant;
    }
    
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

    for(int i = 0; i < N; ++i){

        CelluleM* C = T[i];
        while(C != NULL){
            int res_cmp = strcmp((*C).mot, Mot);
            if(res_cmp == 0){
                
                return (*C).nombre; 
            }
            else if(res_cmp > 0){

                break;
            }
            C = (*C).suivant;
        }
    }
    return 0;    
}

int AjouteDico(ListeM T[], char Mot[]){

    ListeM L;
    int i = Hachage(Mot);

    L = T[i];
    int ret = AjouteListe(&L, Mot);
    
    T[i] = L;
    return ret;
}

void InitDico(ListeM T[N]){

    for(int i = 0; i < N; ++i){
        T[i] = NULL;
    }
}

int NombreMot(ListeM T[]){

    int sum = 0;

    for(int i = 0; i < N; ++i){
        
        CelluleM* C = T[i];
        while(C != NULL){
            
            sum += (*C).nombre;
            C = (*C).suivant;
        }
    }
    return sum;
}

void AfficheDico(ListeM T[]){

    for(int i = 0; i < N; ++i){
        
        printf("%d)\n", i);
        AfficheListe(T[i]);
        printf("\n");
    }
}

void VideListe(ListeM* L){

    while(*L != NULL){

        CelluleM* cp_pt_cell = *L;
        printf("%p %s\n", cp_pt_cell->mot, cp_pt_cell->mot);
        *L = cp_pt_cell->suivant;
        DestroyCell(cp_pt_cell);
    }

}

void VideDico(ListeM T[]){

    for(int i = 0; i < N; ++i){

        VideListe(&T[i]);   
    }
}

void CopyFileToDico(ListeM T[], FILE* file){
    
    while(feof(file) == 0){
        
        char word[50];
        fscanf(file, "%50s", word);
        printf("%p %s\n", word, word);
        AjouteDico(T, word);
    }

    fclose(file);
}

void CopyDicoToFile(ListeM T[], FILE* file){

    for(int i = 0; i < N; ++i){

        CelluleM* L = T[i];

        while(L != NULL){

            fprintf(file, "%s %d\n", L->mot, L->nombre);
            L = L->suivant;
        }
    }
    fclose(file);
}

int main(int argc, char *argv[]){

    ListeM dico[N];
    InitDico(dico);

    FILE* fileR = NULL;
    fileR = fopen(argv[1], "r");

    CopyFileToDico(dico, fileR);
    
    printf("dico plein\n");
    AfficheDico(dico);

    FILE* fileW = NULL;
    fileW = fopen("Examen.cpt", "a+");

    CopyDicoToFile(dico, fileW);

    VideDico(dico);

    printf("dico vide\n");
    AfficheDico(dico);

    return 0;
}