#include <stdlib.h>
#include <stdio.h>

void afficheTab(int tab[], int taille){

    for(int i = 0; i < taille; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
}

void inittab(int** tab){

    *tab = (int*) malloc(sizeof(int)*12);
}

int main(){
    
    int tab[5] = {0, 1, 2, 3, 4};
    int* a = &tab[2];

    *a = 10;
    afficheTab(tab, 5);

    a += 2;
    printf("%d\n", *a);

    int* tab2 = NULL;

    inittab(&tab2);

    printf("%p\n", tab2);











    return 0;

}