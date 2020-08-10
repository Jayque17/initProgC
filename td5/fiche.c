#include <stdio.h>
#include <string.h>

#define MAXNOTES 30
#define MAXFICHES 30



typedef struct date{

    int day;
    char month[15];
    int year;

}Date;


typedef struct fiche{

    char surname[25];
    char name[25];
    Date born;
    char section[2];
    int repeat;
    int td;
    int notes[MAXNOTES];
    int nbnotes;

} Fiche;


typedef struct classe{
    
    int nbfiches; 
    Fiche fiches[MAXFICHES];
    
} Classe;



Date ecrireDate(void){

    Date d;

    scanf("%d", &(d.day));
    scanf("%s", d.month);
    scanf("%d", &(d.year));

    return d;
}


void lireDate(Date d){

    printf("%d %s %d\n", d.day, d.month, d.year);
}


void lireFiche(Fiche f){

    printf("%s %s\n", f.surname, f.name);
    
    lireDate(f.born);
    
    printf("%s\n", f.section);
    
    if(f.repeat == 0){
        printf("R");
    }
    
    printf("%d\n", f.td);

    for(int i = 0; i < f.nbnotes; ++i){
        printf("%d ", f.notes[i]);
    }
    printf("\n");
}


Fiche ecrireFiche(void){

    Fiche f;

    scanf("%s", f.surname);
    scanf("%s", f.name);
    f.born = ecrireDate();
    scanf("%s", f.section);
    scanf("%d", &(f.repeat));
    scanf("%d", &(f.td));
    f.nbnotes = 0;

}


int ajouteNote(Fiche* f){

    if(f->nbnotes < MAXNOTES){
    
        scanf("%d", f->notes[f->nbnotes]);
        f->nbnotes += 1;
        return 1;
    }

    return 0; 
}


int moyenne(Fiche f){

    int sum = 0;

    for(int i = 0; i < f.nbnotes; ++i){

        sum += f.notes[i];
    }

    return sum / f.nbnotes;
}

Classe creerClasse(void){

    Classe c;
    c.nbfiches = 0;
    return c;
}

int ajouteFiche(Fiche f, Classe* c){

    if(c->nbfiches < MAXFICHES){

        c->fiches[c->nbfiches] = f;
        c->nbfiches += 1;

        for(int i = c->nbfiches - 1; i > 0; --i){

            if(strcmp(c->fiches[i].surname, c->fiches[i - 1].surname) == 0){
                if(strcmp(c->fiches[i].name, c->fiches[i - 1].name) < 0){

                    Fiche tmp;
                    tmp = c->fiches[i - 1];
                    c->fiches[i - 1] = c->fiches[i];
                    c->fiches[i] = tmp;
                }
                return 1;
            }
            else if(strcmp(c->fiches[i].surname, c->fiches[i - 1].surname) < 0){
                
                Fiche tmp;
                tmp = c->fiches[i - 1];
                c->fiches[i - 1] = c->fiches[i];
                c->fiches[i] = tmp;
            }
            return 1;
        }     
    }

    return 0; 

}