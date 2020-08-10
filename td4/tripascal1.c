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

void FillPascal(int tab[N][N]){

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){

            tab[i][j] = GiveValue(i, j);
        }
    }
}

void PrintTab(int tab[N][N]){

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){

            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}


int main(void){

    int pascal[N][N];

    FillPascal(pascal);

    PrintTab(pascal);

    return 0;
}