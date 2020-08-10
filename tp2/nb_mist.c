#include <stdio.h>

int main(void){

    int nb, t, ans, vic;
    vic = 0;
    nb = 487;
    printf("le nombre mystere est entre 0 et 1000\n");
    for(t = 0; t < 10; t++){
        scanf("%d", &ans);
        if(ans == nb){
            vic = 1;
            break;
        }
        else if(ans > nb)
            printf("moins\n");
        else
            printf("plus\n");
    }

    if(vic == 1)
        printf("gagne en %d essais\n", t+1);
    else
        printf("perdu\n");
    return 0;
}