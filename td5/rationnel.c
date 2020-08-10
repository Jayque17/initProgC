#include <stdio.h>

typedef struct rational{

    int num;
    int den;

} Ratio;

void Simplifie(int* num, int* denom){

    int max = *num;
    int min = *denom;

    if(max < min){
        int tmp = max;
        max = min;
        min = tmp;
    }

   int res = max - min;
   while(res > 0){
       max = min;
       min = res;
       res = max - min;
   }

   *num /= max;
   *denom /= max;
}

Ratio LireRationnel(Ratio r){

    Simplifie(&(r.num), &(r.den));
    return r;
}

Ratio SommeRationnel(Ratio r1, Ratio r2){

    Ratio r3;
    r3.num = r1.num * r2.den + r2.num * r1.den;
    r3.den = r1.den * r2.den;

    r3 = LireRationnel(r3);
    
    return r3;
}