#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* TYPE */

typedef struct cellule{
    
    int valeur;
    struct cellule* suivant;
        
} Cellule, *Liste;

/* Exercice 5.1 */

typedef struct cellulemot{

    char* mot;
    struct cellulemot* suivant;

} CelluleMot, *ListeMot;


/* FUNCTIONS */

/* Exercice 3.1 */

Liste alloueCellule(int x){

    Cellule* cell = (Cellule*) malloc(sizeof(Cellule));
    cell->valeur = x;
    cell->suivant = NULL;

    return cell;
}

/* Exercice 4 */

Liste libererListe(Liste* l){

    if(*l == NULL){

        return *l;
    }

    if((*l)->suivant != NULL){
        
        libererListe(&(*l)->suivant);
    }

    free(*l);
    *l = NULL;

    return *l;
}

ListeMot libererListeMot(ListeMot* l){

    if(*l == NULL){

        return *l;
    }

    free((*l)->mot); /* free caca */
    if((*l)->suivant != NULL){
  
        libererListeMot(&(*l)->suivant);
    }

    
    free(*l);
    *l = NULL;
    return *l;
}

/* Exercice 1 */

int NombreElement(Cellule* cell){


    if(cell == NULL){
        
        return 0;
    }

    return 1 + NombreElement(cell->suivant);
}

int NombreElementIter(Cellule* cell){


    if(cell == NULL){
        
        return 0;
    }

    Cellule* cell2 = cell;
    int nb = 0;

    while(cell2 != NULL){

        nb += 1;
        cell2 = cell2->suivant;
    }

    return nb;
}


Cellule* RechercheElement(Cellule* cell, int elem){


    if(cell != NULL){

        Cellule* cell2 = cell;
        while(cell2 != NULL){

            if(cell2->valeur == elem){

                return cell2;
            }
            cell2 = cell2->suivant;
        }
    }

    return NULL;
}

Cellule* RechercheElementRec(Cellule* cell, int elem){


    if(cell == NULL){

        return cell;
    }

    if(cell->valeur == elem){

        return cell;
    }

    return RechercheElementRec(cell->suivant, elem);
}


int NombreElementInf(Cellule* cell, int x){


    if(cell == NULL){

        return 0;
    }

    if(cell->valeur < x){

        return 1 + NombreElementInf(cell->suivant, x);
    }
    else{

        return NombreElementInf(cell->suivant, x);
    }
}

int NombreElementInfIter(Cellule* cell, int x){


    Cellule* cell2 = cell;
    int nb = 0;

    while(cell2 != NULL){

        if(cell2->valeur < x){

            nb += 1;
        }

        cell2 = cell2->suivant;
    }

    return nb;
}


Cellule* RechercheMin(Cellule* cell){

    Cellule* cp_cell = cell;
    Cellule* min = cp_cell;

    if(cp_cell != NULL){

        while(cp_cell->suivant != NULL){

            cp_cell = cp_cell->suivant;

            if(min->valeur > cp_cell->valeur){

                min = cp_cell;
            }
        }
    }

    return min;
}

Cellule* ChooseMin(Cellule* c1, Cellule* c2){

    if(c1 == NULL && c2 == NULL){

        return NULL;
    }

    else if(c1 != NULL && c2 == NULL){

        return c1;
    }

    else if(c1 == NULL && c2 != NULL){

        return c2;
    }


    if(c1->valeur > c2->valeur){

        return c2;
    }

    return c1;
}

Cellule* RechercheMinRec(Cellule* cell){

    if(cell == NULL){

        return cell;
    }

    return ChooseMin(cell, RechercheMin(cell->suivant));
}


int estTrie(Cellule* cell){

    Cellule* cell1 = cell;
    Cellule* cell2 = RechercheMin(cell1);

    while(cell1 != NULL){

        if(cell2 != cell1){

            return 0;
        }

        cell1 = cell1->suivant;
        cell2 = RechercheMin(cell1);
    }

    return 1;
}

int estTrieRecc(Cellule* cell){

    if(cell == NULL){

        return 1;
    }
    
    if(RechercheMin(cell) != cell){

        return 0;
    }

    return estTrieRecc(cell->suivant);
}

/* TO DO */
/* functions who returns number of differents elements in list (iter & recc)*/

/* Exercice 2 */

void concatene(Cellule** L1, Cellule** L2){

    Cellule** ptL1 = L1;
    while((*ptL1)->suivant != NULL){

        ptL1 = &(*ptL1)->suivant;
    }

    (*ptL1)->suivant = *L2;
    *L2 = NULL;
}

/* Exercice 3 */

Liste extraitTete(Liste* l){

    Liste tete = NULL;
    tete = *l;
    *l = (*l)->suivant;
    tete->suivant = NULL;
    return tete;
}

int insereTete(Liste* l, int x){

    Cellule* tete = NULL;
    
    tete = alloueCellule(x);
    if(tete == NULL){
        return 0;
    }

    tete->suivant = *l;
    *l = tete;
    return 1;
}

int insereApres(Liste* l, int x, int y){

    Cellule* cible = RechercheElement(*l, x);

    if(cible == NULL){

        cible = *l;

        while(cible->suivant != NULL){
            
            cible = cible->suivant;
        }

        cible->suivant = alloueCellule(y);  
        if(cible->suivant == NULL){

            return 0;
        }     

        return 1; 
    }

    Cellule* tmp = cible->suivant;

    cible->suivant = alloueCellule(y);
    if(cible->suivant == NULL){

        return 0;
    }     

    cible->suivant->suivant = tmp;

    return 1; 
}

void afficheListe(Liste L){

    if(L != NULL){
        printf("%d ", L->valeur);
        afficheListe(L->suivant);
    }

    printf("\n");
}

void afficheListeMot(ListeMot L){

    if(L != NULL){
        printf("%s ", L->mot);
        afficheListeMot(L->suivant);
    }

    printf("\n");
}

/* TODO */
Liste extraitMin(Liste *l);

/* Exercice 5 */
/* Sur les fonctions précedentes, il faut changer le type de retour et les types
passés en paramètres. */

ListeMot alloueCelluleMot(char* m){

    CelluleMot* cellM = (CelluleMot*) malloc(sizeof(CelluleMot));
    cellM->mot = (char*) malloc(sizeof(strlen(m)));
    if(cellM->mot == NULL){

        free(cellM);
        return NULL;
    }

    cellM->mot = m;
    cellM->suivant = NULL;
    return cellM;
}


/* MAIN */

int main(void){

    CelluleMot* cell1 = NULL;

    cell1 = alloueCelluleMot("noel");
    cell1->suivant = alloueCelluleMot("social");
    cell1->suivant->suivant = alloueCelluleMot("saint");

    afficheListeMot(cell1);

    /* erreur */
    libererListeMot(&cell1);
    
    return 0;
}