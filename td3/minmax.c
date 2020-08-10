#include <stdio.h>

void MinMax(int* min, int* max, int n){
    
    int i = 0;
    int val;
    while(i < n){

        printf("Vous devez rentrer la valeur %d / %d\n", i+1, n);
        scanf("%d", &val);

        if(i == 0){
            *min = val;
            *max = val;
        }
        if(val < *min){
            *min = val;
        }
        if(val > *max){
            *max = val;
        }
        ++i;
    }
}

int main(void){

    int n;
    int a;
    int b;

    printf("Choisir le nombre de valeurs : ");
    scanf("%d", &n);

    MinMax(&a, &b, n);

    printf("Le minimum des valeurs rentrées par l'utilisateur est %d\n", a);
    printf("Le maximum des valeurs rentrées par l'utilisateur est %d\n", b);
    
    return 0;
}