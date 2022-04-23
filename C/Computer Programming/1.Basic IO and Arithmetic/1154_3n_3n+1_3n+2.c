#include <stdio.h>

int main(){
    int n, i, a, a1 = 0, a2 = 0, a3 = 0;
    scanf("%d", &n);
    for (i = 0; i < n; ++i){
        scanf("%d", &a);
        switch (a % 3) {
        case 0:
            a1++;
            break;
        case 1:
            a2++;
            break;
        case 2:
            a3++;
            break;
        }
    }
    printf("%d %d %d", a1, a2, a3);
    return 0;
}