#include <stdio.h>

int main(void){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d + %d = %d\n", a, b, a+b);
    
    if(a % 3 == 0 && a % 2 == 0)
        printf("%3d  est divisible par 2 et par 3\n", a);
    else if(a % 3 == 0)
        printf("%3d  est divisible par 3\n", a);
    else if(a % 2 == 0)
        printf("%3d  est divisible par 2\n", a);
    
    if(b % 3 == 0 && b % 2 == 0)
        printf("%3d  est divisible par 2 et par 3\n", b);
    else if(b % 3 == 0)
        printf("%3d  est divisible par 3\n", b);
    else if(b % 2 == 0)
        printf("%3d  est divisible par 2\n", b);
    
    return 0;
}