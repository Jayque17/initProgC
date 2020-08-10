#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef enum {
    maison,
    direction
} Type;

typedef struct _Panneau{

    char* indication;
    struct _Panneau* direction;
    Type type;

} Panneau;

Panneau initPanneau(const char* indication){

    Panneau panneau;
    panneau.indication = (char* )malloc(sizeof(char) * (strlen(indication) + 1));
    panneau.indication = strcpy(panneau.indication, indication);
    panneau.type = maison;

    return panneau;
}

Panneau initDirection(Panneau* pospanneau){
    Panneau panneau;
    panneau.direction = pospanneau;
    panneau.type = direction;

    return panneau;
}

void toquer(Panneau chezquelquun){

    printf("dring je suis entrain de toquer %s\n", chezquelquun.indication);
}

int main(){
    /*  
        n : je lis le panneau
        *n : on suit la direction du panneau
        &n : la position du panneau, on est de type (Panneau*)  
    */

    Panneau fac = initPanneau("école des grands");
    Panneau maison = initPanneau("dodo et manger");
    Panneau meme = initPanneau("Chez mémé");
    Panneau vers_fac = initDirection(&fac);
    Panneau laurent = initPanneau("chez laurent");
    Panneau celine = initPanneau("chez celine");
    Panneau vers_chezceline = initDirection(&celine);
    Panneau verslepanneau_verslepanneau_celine = initDirection(&vers_chezceline);

    /*
        je suis chez celine et je vais toquer
    */
    toquer(celine);

    /*
        je suis devant le panneau qui indique la direction de chez celine
    */
    toquer(*(vers_chezceline.direction));

    /*
        Je suis devant le panneau qui indique le panneau qui indique la direction de chez celine.
    */
    toquer(*(*verslepanneau_verslepanneau_celine.direction).direction);
    toquer(*verslepanneau_verslepanneau_celine.direction->direction);
    
    
    
    vers_chezceline.direction = &laurent;
    toquer(*vers_chezceline.direction);

    maison.direction = &meme;
    maison.type = direction;

    toquer(*maison.direction);
    
    
    
    return 0;
}