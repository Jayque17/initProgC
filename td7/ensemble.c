/* todo realloc when it's too small  to add a value and when 
it's too big too */
#include <stdio.h>
#include <stdlib.h>

typedef struct ensemble {

    int* tab;
    int card;
    int max;
    
} Ens;

int InsertEns(Ens* E, int n){
    
    for(int i = 0; i < E->card; ++i){

        if(E->tab[i] == n){

            return 0;
        }
    }

    E->tab[E->card] = n;

    int i = E->card;

    while(i > 0 && E->tab[i] < E->tab[i - 1]){

        int tmp = E->tab[i - 1];
        E->tab[i - 1] = E->tab[i];
        E->tab[i] = tmp;
        --i;
    }   

    E->card += 1;
    return 1;
}

int Creation(Ens* E){

    int nbelem;

    scanf("%d", &nbelem);

    E->tab = (int*) malloc(sizeof(int) * nbelem);

    if(E->tab == NULL){

        E = NULL;
        return 0;
    }

    E->card = 0;
    E->max = nbelem;

    for(int i = 0; i < E->max; ++i){

        int n = 0;
        scanf("%d", &n);
        InsertEns(E, n);
    }

    return 1;
}


int IsEmpty(Ens* E){

    if(E->card == 0){

        return 1;
    }

    return 0;
}

int countNbElem(const Ens* E){

    return E->card;
}

int IsInEns(const Ens* E, int n){

    for(int i = 0; i < E->card; ++i){

        if(E->tab[i] == n){

            return 1;
        }
    }

    return 0;
}

void DisplayEns(const Ens* E){

    for(int i = 0; i < E->card; ++i){

        printf("%d ", E->tab[i]);
    }

    printf("\nCard : %d\n", E->card);
}

int RemoveElem(Ens* E, int n){

    if(IsInEns(E, n) == 0){

        return 0;
    }

    for(int i = 0; i < E->card; ++i){

        if(E->tab[i] == n){
            
            while(i < E->card - 1){

                int tmp = E->tab[i];
                E->tab[i] = E->tab[i + 1];
                E->tab[i + 1] = tmp;
                ++i;
            }

            E->card -= 1;
            return 1;
        }
    }

    return 0;
}

int AddElem(Ens *E, int n){

    if(E->card == E->max){

        return 0;
    }

    return InsertEns(E, n);
}

void FreeEns(Ens *E){

    free(E->tab);
}

Ens Union(Ens* E1, Ens* E2){

    Ens E3;

    E3.max = E1->card + E2->card;
    E3.tab = (int*) malloc(sizeof(int) * E3.max);
    E3.card = 0;

    for(int i = 0; i < E1->card; ++i){

        InsertEns(&E3, E1->tab[i]);
    }

    for(int i = 0; i < E2->card; ++i){

        InsertEns(&E3, E2->tab[i]);
    }

    return E3;
}

int min(int a, int b){

    if(a < b){

        return a;
    }
    return b;
}

Ens Intersection(Ens* E1, Ens* E2){

    Ens E3;

    E3.max = min(E1->card, E2->card);
    E3.tab = (int*) malloc(sizeof(int) * E3.max);
    E3.card = 0;

    for(int i = 0; i < E1->card; ++i){
    
        for(int j = 0; j < E2->card; ++j){

            if(E1->tab[i] == E2->tab[j]){

                InsertEns(&E3, E1->tab[i]);
            }
        }
    }

    return E3;
}

int main(void){

    Ens E1, E2, E3;

    Creation(&E1);
    InsertEns(&E1, 3);
    InsertEns(&E1, 2);

    // Creation(&E1);
    // printf("E1\n");
    // DisplayEns(E1);
    // Creation(&E2);
    // printf("E2\n");
    // DisplayEns(E2);
    // E3 = Intersection(&E1, &E2);
    // printf("E3\n");
    // DisplayEns(E3);

    // FreeEns(&E1);
    // FreeEns(&E2);
    // FreeEns(&E3);

    // DisplayEns(E1);
    // DisplayEns(E2);
    // DisplayEns(E3);
}
