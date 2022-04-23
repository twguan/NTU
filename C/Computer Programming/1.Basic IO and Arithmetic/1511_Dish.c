#include <stdio.h>

int main(){
    int N, X, Y;
    scanf("%d%d%d", &N, &X, &Y);
    if (N % 2)
        printf("%d", (X-Y) * (N / 2) + X + 20);
    else
        printf("%d", (X-Y) * (N / 2) + Y + 20);    
        return 0;
}