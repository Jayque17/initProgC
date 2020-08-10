#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 30

void initAlea(int t[], int taille, int max){

    for(int i = 0; i < taille; i++){
        t[i] = rand() % (max + 1);
    }
}

void Histogramme(int Note[N], int Histo[21]){
    
    for(int i = 0; i < 21; ++i){
        Histo[i] = 0;
        for(int j = 0; j < N; ++j){
            if(Note[j] == i)
                Histo[i] += 1;
        }
    }
}

void afficheTab(int tab[], int taille){

    for(int i = 0; i < taille; ++i){
        printf("%d ", tab[i]);
    }
    printf("\n");
}


int main(void){

    int Note[N];
    int Histo[21];

    srand(time(NULL));

    initAlea(Note, N, 20);

    Histogramme(Note, Histo);

    printf("Note\n");
    afficheTab(Note, N);

    printf("Histo\n");
    afficheTab(Histo, 21);


}