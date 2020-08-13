#include <stdio.h>

typedef struct cellule{
    
    int valeur;
    struct cellule* suivant;
        
} Cellule, *Liste;


typedef struct cellulemot{

    char* mot;
    struct cellulemot* suivant;

} CelluleMot, *ListeMot;



int NombreElement(Cellule* cell){

    /* Compléxité = O(n) */

    if(cell == NULL){
        
        return 0;
    }

    return 1 + NombreElement(cell->suivant);
}

int NombreElementIter(Cellule* cell){

    /* Compléxité = O(n) */

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

    /* Compléxité = O(n) */

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

    /* Compléxité = O(n) */

    if(cell == NULL){

        return cell;
    }

    if(cell->valeur == elem){

        return cell;
    }

    RechercheElementRec(cell->suivant, elem);
}

int NombreElementInf(Cellule* cell, int x){

    /* Compléxité = O(n) */

    if(cell == NULL){

        return -1;
    }

    if(cell->valeur < x){

        return 1 + NombreElementInf(cell->suivant, x);
    }
    else{

        return NombreElementInf(cell->suivant, x);
    }
}

int NombreElementInfIter(Cellule* cell, int x){

    /* Compléxité = O(n) */

    if(cell != NULL){

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

    return -1;
}

Cellule* RechercheMin(Cellule* cell){

    /* Compléxité = O(n) */

    if(cell != NULL){

        Cellule* cell2 = cell;
        int min = cell2->valeur;
        
        cell2 = cell2->suivant;

        while(cell2 != NULL){

            if(cell2->valeur < min){

                min = cell2->valeur;
            }

            cell2 = cell2->suivant;
        }

        return cell2;
    }

    return NULL;
}

Cellule* RechercheMinRec(Cellule* cell){

    if(cell == NULL){

        return NULL;
    }

    if(cell->suivant == NULL){

        return cell;
    }
    
    /* À finir */
}

int estTrie(Cellule* cell){

    /* Compléxité = O(n) */

    if(cell == NULL){

        return 1;
    }

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

int estTrieRec(Cellule* cell){

    /* Compléxité = O(n) */

    if(cell == NULL){

        return 1;
    }

    if(cell->valeur > cell->suivant->valeur){

        return 0;
    }

    return estTrie(cell->suivant);
}

void concatene(Cellule* L1, Cellule* L2){

    Cellule* ptL1 = L1;
    while(ptL1->suivant != NULL){

        ptL1 = ptL1->suivant;
    }

    ptL1->suivant = L2;
    L2 = NULL;
}

Liste alloueCellule(int x){

    Cellule* cell = (Cellule*) malloc(sizeof(Cellule));
    cell->valeur = x;
    cell->suivant = NULL;

    return cell;
}

/* TODO */
Liste extraitTete(Liste* l){}

int insereTete(Liste* l, int x){

    Cellule* cp = *l;
    *l = alloueCellule(x);
    if(*l == NULL){

        return 0;
    }
    (*l)->suivant = cp;
    cp = NULL;

    return 1;
}

int insereApres(Liste *l, int x, int y){

    Cellule* target = RechercheElement(*l, x);
    if(target == NULL){

        Cellule* cp = *l;

        while(cp->suivant != NULL){
            
            cp = cp->suivant;
        }

        cp->suivant = alloueCellule(y);
        if(cp->suivant == NULL){

            return 0;
        }
    }

    Cellule* cp = target->suivant;
    target->suivant = alloueCellule(y);
    if(target->suivant == NULL){

        return 0;
    }

    target->suivant->suivant = cp;
    cp = NULL;

    return 1;
}

/* TODO */
Liste extraitMin(Liste *l){}
Cellule* duplique(Cellule* list){}

/* TOCHECK */
void libererListe(Liste* l){

    if((*l)->suivant == NULL){
        free(*l);
    }
    else{
        libererListe(&(*l)->suivant);
    }
}

/* TODO ex5.2 */

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

/* TODO ex5.4 */


/* TOCHECK TODO */
Cellule* Shuffle(Cellule** l1, Cellule** l2){

    if(*l1 == NULL && *l2 == NULL){

        return NULL;
    }

    /* TOCHECK */
    Cellule* cp1; = (*l1)->suivant;
    
    while (*l2 != NULL)
    {
        if(cp1 == NULL && *l2 != NULL){

            cp1 = *l2;
            *l2 = NULL;
        }

        cp1 = *l2;



        
    }
    



    
    
    return *l1;


}