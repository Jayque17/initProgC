#include <stdio.h>

int main(void){
    int a, b, tmp;
    scanf("%d%d", &a, &b);
    if(a < b){
        tmp = a;
        a = b;
        b = tmp;
    }
    else
        b += 10;
    printf("%d %d\n", a, b);
    return 0;
    
}