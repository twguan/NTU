#include <stdio.h>

int sum(int n){
    if (n == 1)
        return n;
    else
        return (n*n + sum(n - 1));
}

int main(){
    int n, i;
    scanf("%d", &n);
    printf("%d", sum(n));
    return 0;
}
