#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initAlea(int t[], int taille, int max){

    for(int i = 0; i < taille; i++){
        t[i] = rand() % (max + 1);
    }
}

int main(void){

    srand(17);
    
    int i = 0;
    printf("20 nombre aléatoire sans srand(time(NULL))\n");
    while(i < 20){
        printf("%d\n", rand());
        i ++;
    }
    /* Avec une même graîne on à les mêmes valeurs aléatoires. */

    srand(time(NULL));
    
    i = 0;
    printf("20 nombre aléatoire avec srand(time(NULL))\n");
    while(i < 20){
        printf("%d\n", rand());
        i ++;
    }
    /* A chaque lancement du programme les valeurs aléatoires changent. */

    int tab[8];
    initAlea(tab, 8, 30);

    printf("test function initAlea\n");

    for(i = 0; i < 8; i++){
        printf("%d\n", tab[i]);
    }
}