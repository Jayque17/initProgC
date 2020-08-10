#include <stdio.h>

char *plur(int val){

    if(val > 1)
        return "s ";
    else
        return " ";
}

int main(void){

    int j, se, m, a, si;
    
    printf("Entrer un nombre de jours : ");
    scanf("%d", &j);
    printf("%d jours correspondent à :\n", j);

    m = j / 30;
    j = j % 30;

    se = j / 7;
    j = j % 7;

    a = m / 12;
    m = m % 12;

    si = a / 100;
    a = a % 100;

    printf("%d siecle%s%d annee%s%d mois %d semaine%s%d jour%s\n", si, plur(si), a, plur(a), m, se, plur(se), j, plur(j));
    
    return 0;
}