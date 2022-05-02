#include <stdio.h>

int fact(int n){
    if (!n)
        return 1;
    int num = 1;
    for (int i = 2; i <= n; i++)
        num *= i;
    return num;
}

int perm(int n, int m){
    if (n < m)
        return 0;
    return fact(n) / fact(n-m);
}

int comb(int n, int m){
    if (n < m)
        return 0;
    return perm(n, m) / fact(m);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n%d", perm(n, m), comb(n, m));
}