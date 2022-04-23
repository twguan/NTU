#include <stdio.h>

int main(){
    int n, j, l;
    scanf("%d", &n);
    if (n <= 540000){
        j = 5;
        l = 0;
    }
    else if (n <= 1210000){
        j = 12;
        l = 37800;
    }
    else if (n <= 2420000){
        j = 20;
        l = 134600;
    }
    else if (n <= 4530000){
        j = 30;
        l = 376600;
    }
    else if (n <= 10310000){
        j = 40;
        l = 829600;
    }
    else{
        j = 45;
        l = 1345100;
    }
    printf("%d%% %d %d %d ", j, n*j/100, l, n*j/100 - l);
    return 0;
}