#include <stdio.h>

int main(){
    long long int n;
    int i, count;
    while(scanf("%lld", &n) != EOF){
        count = 0;
        for (i = 0; i < 64; ++i){
            if ((n>>i) & 1)
                count++;
        }
        printf("%d\n", count);
    }
    return 0;
}