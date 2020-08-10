#include <stdio.h>
#include <string.h>


int CompteMots(FILE* fichier){

    /* La fonction prend en argument un fichier.
    Elle compte le nombre de mots dans le fichier.
    Elle renvoie ce nombre. */
    
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


int CompteCaracteres(FILE* fichier){

    /* La fonction prend en argument un fichier.
    Elle compte le nombre de caractères dans le fichier.
    Elle renvoie ce nombre. */
    
    int count = 0;
    for(char ch = getc(fichier); ch != EOF; ch = getc(fichier)){

        count += 1;
    }

    return count;
}


int CompteLignes(FILE* fichier){
    
    /* La fonction prend en argument un fichier.
    Elle compte le nombre de lignes dans le fichier.
    Elle renvoie ce nombre. */
    
    int count = 0;
    for(char ch = fgetc(fichier); ch != EOF; ch = fgetc(fichier)){
        if(ch == '\n'){

            count += 1;
        }
    }

    count += 1;
    return count;
}


void usage(char* nom){

    /* La fonction affiche la documentation pour l'utilisation du programme my_wc. */

    printf("\nNAME\n");
    printf("\tmy_wc count number of characteres, words and lines from files and print on the standard output.\n\n");
    printf("SYNOPSIS\n");
    printf("\tmy_wc [mlvc][fichier1][fichier2]...\n\n");
    printf("DESCRIPTION\n");
    printf("\t-m, show number of words\n\n");
    printf("\t-l, show number of lines\n\n");
    printf("\t-c, show number of characters\n\n");
    printf("\t-v, show who made this program\n\n");
    printf("AUTHOR\n");
    printf("\tWritten by Julien Noël.\n");
}

void DoVOption(void){
    /* La fonction affiche un message. */
    printf("\nThis word count program was made by Julien NOËL.\n\n");
}


int FileExist(const char * filename){
    
    /* La fonction prend en argument un nom de fichier(ou chemin vers un fichier).
    Elle vérifie si ce fichier peut être lu.
    On renvoie 1 si c'est le cas, 0 sinon. */
    
    FILE* file;
    if((file = fopen(filename, "r"))){
        fclose(file);
        return 1;
    }

    printf("Le fichier %s n'existe pas.\n", filename);
    return 0;
}


int execOption(char* progName, char* option, FILE* fichier, const char * filename){

    if(option[0] != '-'){

        return -1;
    }

    for(int i = 1; i < strlen(option); ++i){

        rewind(fichier);
        switch(option[i]){

            case 'm':
                printf("Le fichier %s contient %d mot(s).\n", filename,CompteMots(fichier));
                break;

            case 'l':
                printf("Le fichier %s contient %d ligne(s).\n", filename,CompteLignes(fichier));
                break;

            case 'v':
                DoVOption();
                break;

            case 'c':
                printf("Le fichier %s contient %d caractère(s).\n", filename,CompteCaracteres(fichier));
                break;

            default:
                usage(progName);
                return 0;

        }
    }

    return 1;
}



int main(int argc, char* argv[]){

    for(int i = 2; i < argc - 1; ++i){

        if(FileExist(argv[i]) == 1){

            FILE* fichier = fopen(argv[i], "r");
            int check = execOption(argv[0], argv[1], fichier, argv[i]);
            fclose(fichier);
            if(check == 0){
                
                break;
            }
        }    
        
    }

    return 0;
}