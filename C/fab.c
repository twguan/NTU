#include <stdio.h>

int fib[20];

int fibo(int n){
    if (n < 2)
        return fib[n];
    for (int i = 2; i <= n; i++)
        fib[i] = fib[i-1] + fib[i-2];

    return fib[n];
}

int main(){
    int n;
    scanf("%d", &n);
    fib[0] = 0;
    fib[1] = 1;
    printf("fib: %d", fibo(n));
    return 0;
}