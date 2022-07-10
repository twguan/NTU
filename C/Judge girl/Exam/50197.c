#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1000; i < 10000; i++){
        int a = i/1000, b = i/100%10, c = i/10%10, d = i%10;
        if (abs(a-b) <= n && abs(b-c) <= n && abs(c-d) <= n)
            printf("%d\n", i);
    }
    return 0;
}