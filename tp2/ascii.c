#include <stdio.h>

int main(void){
    
    char c;
    int n;
    scanf("%c", &c);
    switch(c){
        case '0':
            n = 0; break;
        case '1':
            n = 1; break;
        case '2':
            n = 2; break;
        case '3':
            n = 3; break;
        case '4':
            n = 4; break;
        case '5':
            n = 5; break;
        case '6':
            n = 6; break;
        case '7':
            n = 7; break;
        case '8':
            n = 8; break;
        case '9':
            n = 9; break;
        default:
            n = (int) c; break;
    }
    printf("caractere %c code %d\n", c, n);
    return 0;
}