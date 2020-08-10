#include <stdio.h>

int main(void){
    int fin;
    char col;
    fin = 0;
    do{
        
        printf("choose a color\n");
        printf("red, blue, green or quit [r, g, b, q] : \n");
        scanf("%c", &col);
        switch (col)
        {
        case 'r':
            printf("red\n");
            fin = 1;
            break;
        
        case 'b':
            printf("blue\n");
            fin = 1;
            break;
        
        case 'g':
            printf("green\n");
            fin = 1;
            break;
        
        case 'q':
            fin = 1;
            break;

        default:
            printf("This color is unauthorized\n");
            break;
        }

    } while(fin != 1);
    return 0;
}