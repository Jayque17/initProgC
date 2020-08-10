#include <stdio.h>

#define N 10

int GiveValue(int i, int j){

    if(i == j || j == 0){

        return 1;
    }
    else if(j > i){

        return 0;
    }
    return GiveValue(i - 1, j) + GiveValue(i - 1, j - 1);
}

void FillPascal(int tab[N], int* i){


    for(int j = 0; j < N; ++j){

        tab[j] = GiveValue(*i, j);    
    }

    *i += 1;
}

void PrintTab(int tab[N]){

    int i = 0;
    while(i < N){

        FillPascal(tab, &i);

        for(int j = 0; j < N; ++j){

            printf("[%d]", tab[j]);
        }

        printf("\n");
    }
}

int main(void){
    
    int pascal[N];
    PrintTab(pascal);
    return 0;
}