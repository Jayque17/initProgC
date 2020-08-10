#include <stdio.h>
#include <stdlib.h>

void applyminus2(int* n){

    *n -= 2;
}


void changeentrois(int* n){

    *n = 5;
    printf("%d\n", *n);
    applyminus2(n);

}

void changec(int** n, int* m){

    *n = m;
}


int main(){

    int a = 80;
    int b = 78;
    int* c = &b;

    
    /*changeentrois(&a);
    printf("%d\n", a);
    */
    printf("%d\n", *c);
    changec(&c, &a);
    a = 4;
    printf("%d\n", *c);



    return 0;
}