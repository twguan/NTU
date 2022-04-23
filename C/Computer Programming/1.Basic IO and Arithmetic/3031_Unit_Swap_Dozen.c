#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if (n % 12)
        printf("%d dozen and %d", n/12, n%12);
    else
        printf("%d dozen", n/12);
    return 0;
}