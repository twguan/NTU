#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
        printf(" ");
    printf("*\n");
    for (int i = 1; i <= n-2; ++i){
        for (int j = 0; j < 3; ++j){
            for (int k = n-i-j; k > 0; --k)
                printf(" ");
            for (int k = 1; k <= 2*i-1+2*j; ++k)
                printf("^");
            printf("\n");
        }
    }
    for (int i = 1; i <= n-2; ++i){
        for (int j = 1; j <= n/2+1; ++j)
            printf(" ");
        for (int k = 1; k <= n-2; ++k)
            printf("#");
        printf("\n");
    }
    return 0;
}