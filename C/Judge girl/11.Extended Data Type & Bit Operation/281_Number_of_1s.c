#include <stdio.h>

int main(){
    int n, i;
    while(scanf("%d", &n) != EOF) {
    int count = 0;
    for (i = 0; i < 32; ++i){
        if (n & (1<<i))
            count++;
    }
    printf("%d\n", count);
    }
    return 0;
}