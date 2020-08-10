#include <stdio.h>

int sumDigits(int n){
    if(n == 0){
        return 0;
    }
    return sumDigits(n/10) + n % 10;

}

int powerIntegers(int n, int p){
    if(p == 0){
        return 1;
    }
    return powerIntegers(n, p - 1) * n;
}