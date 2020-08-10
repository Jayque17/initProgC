#include <stdio.h>

void ajouteDix(int *n){
    *n += 10;
}

void echange(int *n, int *m){
    int tmp;
    tmp = *n;
    *n = *m;
    *m = tmp;
}

int main(void){

    int n, m;
    scanf("%d %d", &n, &m);
    printf("n : %d %p\n", n, (void*) &n);
    printf("m : %d %p\n", m, (void*) &m);

    ajouteDix(&n);
    printf("n + 10 : %d %p\n", n, (void*) &n);

    echange(&n, &m);
    printf("echange de n et m\n");
    printf("n : %d %p\n", n, (void*) &n);
    printf("m : %d %p\n", m, (void*) &m);

    return 0;
}