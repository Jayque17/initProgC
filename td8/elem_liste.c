#include <stdio.h>

typedef struct cellule{
    
    int valeur;
    struct cellule* suivant;
        
} Cellule, *Liste;


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