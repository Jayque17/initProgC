#include <stdio.h>

int lireLigne(char s[], int taille){

    fgets(s, taille, stdin);

    int i;
    for(i = 0; i < taille; ++i){
        if(s[i] == '\n'){

            break;
        }
    }

    return i;
}

int main(void){
    
    char s[10];

    int res = lireLigne(s, 10);

    printf("%d\n", res);

    printf("%s\n", s);

    return 0;
}