#include <stdio.h>

void return2num(int n, int *factRst, int *sumRst){
    if (n == 0){
        *factRst = 1;
        *sumRst = 0;
    }
    else {
        int num = 1;
        for (int i = 2; i <= n; i++)
            num *= i;
        *factRst = num;
        *sumRst = n*(n+1)/2;
    }
}

int main(){
    int n, f, s;
    scanf("%d", &n);
    int *facRst = &f;
    int *sumRst = &s;
    return2num(n, facRst, sumRst);
    printf("%d\n%d", *facRst, *sumRst);
    return 0;
}