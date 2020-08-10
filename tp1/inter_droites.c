/*
On cherche à resoudre le système
y = ax + b
y = mx + p
*/

#include <stdio.h>

int main(void){
    float x, y;
    int a, b, m, p;
    printf("Entrer les coeffiscient de la première droite : ");
    scanf("%d %d", &a, &b);
    printf("Entrer les coeffiscient de de la deuxième droite : ");
    scanf("%d %d", &m, &p);

    x = (float)(p - b)/(a - m);
    y = a*x + b;
    printf("Le point d'intersection des 2 droites est (%f, %f)\n", x, y);
    return 0;
}