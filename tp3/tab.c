#include <stdio.h>

void afficheTab(int tab[], int taille){
    
    int i;
    for(i = 0; i < taille; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
}

void changeTab(int tab[], int indice){
    
    tab[indice] += 2;
    printf("%d %d\n", tab, &tab[0]);
}

int main(void){
    
    int tab[5] = {1, 2, 3, 4, 5};

    afficheTab(tab, 5);

    changeTab(tab, 0);

    afficheTab(tab, 5);

    printf("%d %d\n", tab, &tab[0]);

    return 0;
}