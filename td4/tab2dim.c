#include <stdio.h>

#define N 10

void PutStar(char tab[N][N], int line, int col){

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){

            tab[i][j] = ' ';
        }
    }

    tab[line][col] = '*';
}

void PutCrossNO(char tab[N][N], int line, int col){

    while(col > 0 && line > 0){
        
        tab[line - 1][col - 1] = '+';
        line -= 1;
        col -= 1;
    }
}

void PutCrossNE(char tab[N][N], int line, int col){

    while(line > 0 && col < N - 1){
        
        tab[line - 1][col + 1] = '+';
        line -= 1;
        col += 1;
    }
}

void PutCrossSE(char tab[N][N], int line, int col){

    while(line < N - 1 && col < N - 1){
        
        tab[line + 1][col + 1] = '+';
        line += 1;
        col += 1;
    }
}

void PutCrossSO(char tab[N][N], int line, int col){

    while(line < N - 1 && col > 0){
        
        tab[line + 1][col - 1] = '+';
        line += 1;
        col -= 1;
    }
}

void PutCharTab(char tab[N][N], int line, int col){

    PutStar(tab, line, col);
    PutCrossNO(tab, line, col);
    PutCrossNE(tab, line, col);
    PutCrossSE(tab, line, col);
    PutCrossSO(tab, line, col);
}

void PrintTab(char tab[N][N]){

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){

            printf("[%c]", tab[i][j]);
        }
        printf("\n");
    }
}


int main(void){

    char tab[N][N];
    int line, col;

    printf("Choisir un numéro de ligne et de colonne, entre 0 et %d\n", N);
    scanf("%d", &line);
    scanf("%d", &col);
    printf("\n");

    PutCharTab(tab, line, col);

    PrintTab(tab);

    return 0;
}