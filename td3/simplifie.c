#include <stdio.h>

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

int Simplifie2(int* num, int* denom){

    if(*denom == 0){
        return 0;
    }
    else{
        Simplifie(num, denom);
        printf("%d %d\n", *num, *denom);
        return 1;
    }
}

int main(void){

    int a = 0;
    int b = 0;

    printf("%d %d\n", a, b);
    Simplifie2(&a, &b);


}