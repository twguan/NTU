#include <stdio.h>

int main(){
    int n, i;
    scanf("%d", &n);
    for (i = 1; i < n; ++i)
        printf("%d\n", i);
    for (i = 0; i < n; ++i)
        printf("%d\n", n-i);
    return 0;
}