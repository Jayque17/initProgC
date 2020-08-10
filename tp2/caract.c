#include <stdio.h>

int main(void){
    char a, b;
    scanf("%c", &a);
    scanf(" %c", &b);

    printf("*%c*\n", a);
    printf("*%c*\n", b);
    return 0;
}