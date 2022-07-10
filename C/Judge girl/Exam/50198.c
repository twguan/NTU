#include <stdio.h>

int digit(int n){
    int a[10] = {}, sum = 0;
    while(n){
        if (!a[n%10]){
            sum++;
            a[n%10] = 1;
        }
        n /= 10;
    }
    return sum;
}

int main(){
    int a, b, x;
    while(scanf("%d%d%d", &a, &b, &x) != EOF){
        while(digit(x) > 2){
            x = a*x%b;
        }
        printf("%d\n", x);
    }
    // while (scanf("%d", &a) != EOF)
    //     printf("%d\n", digit(a));
    return 0;
}