#include <stdio.h>

int divide(int num, int div, int *tab){
    
    if(div == 0)
        return 0;
    tab[0] = num / div;
    tab[1] = num % div;
    return 1;
}

int main(void){

    int tab[2], num, div;
    num = 15;
    div = 4;

    divide(num, div, tab);

    printf("%d %d\n", tab[0], tab[1]);

    return 0;
}