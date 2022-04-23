#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for (int i = n; i > 0; --i)
        printf("data %d\n", i);
    printf("\n");
    for (int i = 1; i <= n; ++i)
        printf("data %d\n", i);
    return 0;
}