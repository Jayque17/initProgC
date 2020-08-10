#include <stdio.h>
#define TAILLE 10

void FillTab(int tab[TAILLE]){
    
    for(int i = 0; i < TAILLE; ++i){
        scanf("%d", tab[i]);
    }
}

void CopyTab(int tab1[TAILLE], int tab2[TAILLE]){

    for(int i = 0; i < TAILLE; ++i){
        tab2[i] = tab1[i];
    }
}

void PrintTab(int tab[TAILLE]){

    for(int i = 0; i < TAILLE; ++i){
        
        printf("%d ", tab[i]);
        
        if(i % 9 == 0){
        
            printf("\n");
        }
    }
}

int SumTab(int tab[TAILLE]){

    int sum = 0;

    for(int i = 0; i < TAILLE; ++i){

        sum += tab[i];
    }

    return sum;
}

int AverageTab(int tab[TAILLE]){

    return (SumTab(tab) / TAILLE);
    
}

void MirrorSlice(int tab[TAILLE], int min, int max){

    int tmp = 0;

    while(min != (max - 1) || min != max){
        
        tmp = tab[min];
        tab[min] = tab[max - 1];
        tab[max - 1] = tmp;
        min += 1;
        max -= 1;
    }
}

void ShiftR(int t[], int taille){

    int tmp = t[taille - 1];

    for(int i = 1; i < taille; ++i){
        
        t[i] = t[i - 1];
    }

    t[0] = tmp;
}

void ShiftRk(int t[], int taille, unsigned int k){

    int i = 0;
    while(i < k){
        
        ShiftR(t, taille);
        i += 1;
    }
}