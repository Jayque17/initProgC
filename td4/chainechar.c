#include <stdio.h>

int longueur(char s[]){

    int i = 0;
    while(s[i] != '\0'){
        
        ++i;
    }

    return i;
}

void copie(char dest[], char origine[]){

    int i = 0;
    while(origine[i] != '\0'){

        dest[i] = origine[i];
        ++i;
    }
}

void concat(char dest[], char origine[]){

    int i = 0;
    int j = 0;
    while(dest[i] != '\0'){
        
        ++i;
    }
    while(origine[j] != '\0'){

        dest[i] = origine[j];
        ++i;
        ++j;
    }
    dest[i] = '\0';
}

int compare(char un[], char deux[]){

    int i = 0;

    while(un[i] == deux[i]){

        if(un[i] == '\0'){
            
            break;
        }

        ++i;
    }

    return un[i] - deux[j];
}

int lireLigne(char s[], int taille){

    fgets(s, taille, stdin);

    for(int i = 0; i < taille; ++i){
        if(s[i] == '\0'|| s[i] == '\n'){

            return i;
        }
    }
}