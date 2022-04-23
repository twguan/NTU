#include <stdio.h>

int main(){
    int n, go = 1;
    scanf("%d", &n);
    if (!(n % 7))
        printf("YES\n");
    else {
        while (n > 1) {
            if (n % 10 == 7) {
                printf("YES\n");
                go = 0;
                break;
            }
            n /= 10;
        }
        if (go)
            printf("NO\n");
    }
    return 0;
}