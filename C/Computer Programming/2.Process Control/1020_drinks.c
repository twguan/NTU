#include <stdio.h>

int main(){
    int n, i, cap, total = 0;
    scanf("%d", &n);
    total += n;
    cap = n;
    while (cap >= 4){
        n = cap / 4;
        cap -= 4*n;
        total += n;
        cap += n;
        if (cap == 3){
            total += 1;
            break;
        }
    }
    printf("%d", total);
    return 0;
}