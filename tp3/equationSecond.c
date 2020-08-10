
#include <stdio.h>
#include <math.h>
/* BUT : resoud une equation du second degre    */
/* PARAMETRES :                                 */
/*     3 valeurs float :les coefficients        */
/*     2 adresses  de float: 2 solutions possibles*/
/* RETOUR : le nombre de solutions               */
/* -1 infinité de solutions                     */
/* 0 pas de solution                            */
/* 1 un racine placee a l'adresse x             */
/* 2 deux racines placees aux adresses x et y   */

int resoudre(float a,float b,float c,float *x,float *y){
    float delta;

    if(a == 0)
        return -1;
    delta = (b*b) - 4*a*c;
    if(delta < 0)
        return 0;
    if(delta == 0){
        *x = (-b)/(2*a);
        return 1;
    }
    else{
        *x = (-b + sqrt(delta))/(2*a);
        *y = (-b - sqrt(delta))/(2*a);
        return 2;
    }
}

int main(void){
    float a,b,c;
    float racine,racinePrime;
    int i;
    for(i=0;i<10;i+=1){
        
        scanf("%f %f %f",&a,&b,&c);
        switch(resoudre(a,b,c,&racine ,&racinePrime)){
            
            case -1 : printf("infinite \n"); break;
            case 0 : printf("pas de solution \n"); break;
            case 1 : printf("une solution %f \n",racine); break;
            case 2 : printf("deux solutions %f et %f \n",racine,racinePrime);
        }
    }
    return 0;
}
