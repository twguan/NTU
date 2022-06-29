#include <stdio.h>

int main(){
    double n;
    double sum = 0;
    int a;
    while(1){
        if (scanf("%lf", &n) == 0)
            break;
        a = n;
        sum += n-a;
    }
    printf("%.2f", sum);
    return 0;
}