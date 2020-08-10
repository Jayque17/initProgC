/* 
y = ax + b
on a 2 points de A et B de la droite
a = (YB - YA)/(XB - XA)
b = YA - aXA
*/

#include <stdio.h>

int main(void){
    int px, py, qx, qy, a, b;
    printf("Entrer les coordonées de P : ");
    scanf("%d %d", &px, &py);
    printf("Entrer les coordonées de Q : ");
    scanf("%d %d", &qx, &qy);

    a = (qy - py)/(qx - px);
    b = py - a*px;
    printf("L'équation de la droite passant par P et Q est y = %d*x + %d\n", a, b);
    return 0;
}