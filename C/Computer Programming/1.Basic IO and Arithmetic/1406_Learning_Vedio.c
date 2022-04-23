#include <stdio.h>

int main(){
    int L, S, count = 0;
    scanf("%d%d", &L, &S);
    while (L != S){
        if (L > S){
            S += 5;
            count++;
        }
        else{
            S -= 2;
            count++;
        }
    }
    printf("%d", count);
    return 0;
}