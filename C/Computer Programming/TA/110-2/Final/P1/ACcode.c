#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2*n-1; i++){
        if (i == n-1)
            printf("^");
        else
            printf(" ");
    }
    printf("\n");
    for (int i = 1; i < n; i++){
        for (int j = 0; j < 2*n-1; j++){
            if (j == n-1-i)
                printf("/");
            else if (j == n-1+i)
                printf("\\");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}