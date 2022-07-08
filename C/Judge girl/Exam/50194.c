#include <stdio.h>

int digit(int num){
    int ct = 0;
    while(num){
        num /= 10;
        ct++;
    }
    return ct;
}

int main(){
    int k, l, n, ct = 0;
    scanf("%d%d", &k, &l);
    scanf("%d", &n);
    while (n){
        int t = n % k, d = digit(n), go = 1;
        if (ct + t*d > l){
            if (t*d <= l){
                printf("\n");
                ct = 0;
            }
            else
                go = 0;
        }
        if (go)
            for (int i = 0; i < t; i++){
                printf("%d", n);
                ct += d;
            }

        scanf("%d", &n);
    }
    return 0;
}