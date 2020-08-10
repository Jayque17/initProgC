#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void initAlea(int t[], int taille, int max){

    for(int i = 0; i < taille; i++){
        t[i] = rand() % (max + 1);
    }
}

void sommeTab(int A[N], int B[N], int Resultat[N]){

    for(int i = 0; i < N; ++i){
        Resultat[i] = A[i] + B[i];
    }
}

void afficheTab(int tab[], int taille){

    for(int i = 0; i < taille; ++i){
        printf("%d ", tab[i]);
    }
    printf("\n");
}

int main(void){
    
    int a[N];
    int b[N];
    int c[N];

    initAlea(a, N, 10);
    initAlea(b, N, 6);
    sommeTab(a, b, c);

    printf("A\n");
    afficheTab(a, N);
    printf("B\n");
    afficheTab(b, N);
    printf("C\n");
    afficheTab(c, N);

}