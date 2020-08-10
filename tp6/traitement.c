#include <stdio.h>

int fileExists(const char * filename){
    
    FILE* file;
    if((file = fopen(filename, "r"))){
        fclose(file);
        return 1;
    }

    return 0;
}

int CompteCaracteres(FILE* fichier){
    
    int count = 0;
    for(char ch = fgetc(fichier); ch != EOF; ch = fgetc(fichier)){

        count += 1;
    }
    return count;
}

int CompteLignes(FILE* fichier){
    
    int count = 0;
    for(char ch = fgetc(fichier); ch != EOF; ch = fgetc(fichier)){

        if(ch == '\n'){

            count += 1;
        }
    }
    count += 1;
    return count;
}

int CompteMots(FILE* fichier){
    
    int countch = 0;
    int countw = 0;
    for(char ch = fgetc(fichier); ch != EOF; ch = fgetc(fichier)){

        if(ch != ' ' && ch != '\t' && ch != '\n'){
            countch += 1;
        }
        else{
            if(countch > 0){
                countw += 1;
                countch = 0;
            }
        } 
    }
    return countw;
}

int main(int argc, char* argv[]){

    printf("nb arguments : %d\n", argc);

    int count = 0;
    for(int i = 0; i < argc; ++i){

        if(argv[i][0] == '-'){
            count += 1;
        }
        else{
            if(fileExists(argv[i]) == 1){
                printf("%s peut être lu.\n", argv[i]);
            }
        }
    }   

    printf("nb arguments avec - : %d\n", count);

    FILE* fichier1 = fopen(argv[argc  - 1], "r");
    printf("nombre de caractères dans le fichier test : %d\n", CompteCaracteres(fichier1));
    fclose(fichier1);
    FILE* fichier2 = fopen(argv[argc  - 1], "r");
    printf("nombre de lignes dans le fichier test : %d\n", CompteLignes(fichier2));
    fclose(fichier2);
    FILE* fichier3 = fopen(argv[argc  - 1], "r");
    printf("nombre de mots dans le fichier test : %d\n", CompteMots(fichier3));
    fclose(fichier3);
}