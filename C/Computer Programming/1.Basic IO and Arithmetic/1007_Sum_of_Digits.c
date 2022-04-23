#include <stdio.h>

int main(){
    int a, sum = 0, i;
    scanf("%d", &a);
    sum += a % 10;
    for (i = 0; i < 3; ++i){
        a /= 10;
        sum += a % 10;
    }
    printf("%d", sum);
    return 0;
}