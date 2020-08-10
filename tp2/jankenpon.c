#include <stdio.h>

int LireInf2(int j){
    
    int fin;
    fin = 0;
    do{
        printf("Entrer un chiffre entre 0 et 2 :\n");
        scanf("%d", &j);
        switch (j){
            
            case 0:
            fin = 1; break;

            case 1:
            fin = 1; break;

            case 2:
            fin = 1; break;

            default:
            break;
        }
    } while(fin != 1);

    return j;
}

int arbitre(int j1, int j2){

    if(j1 == j2)
        return 0;
    else if(j1 == (j2 + 1) % 3)
        return 1;
    else
        return 2;
    
}

int main(void){

    int j1, j2, win, manche, score1, score2;
    j1 = 0;
    j2 = 0;
    win = 0;
    manche = 0;
    score1 = 0;
    score2 = 0;

    while(manche < 10){
        
        printf("Joueur 1 choisissez votre arme papier (0), ciseaux (1) ou cailloux (2)\n");
        j1 = LireInf2(j1);
        printf("Joueur 2 choisissez votre arme papier (0), ciseaux (1) ou cailloux (2)\n");
        j2 = LireInf2(j2);

        printf("\n");
        printf("arme j1 : %d\n", j1);
        printf("arme j2 : %d\n", j2);

        win = arbitre(j1, j2);
        
        if(win == 0)
            printf("Egalité\n");
        else{
            printf("Le joueur %d remporte la manche\n", win);
            if(win == 1)
                score1 += 1;
            else
                score2 += 1;
        }
        
        manche += 1;
        printf("j1 : %d VS j2 : %d\n", score1, score2);
    }

    return 0;

}