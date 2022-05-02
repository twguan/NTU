#include <stdio.h>
#include <stdlib.h>

void ans(int n,int k, int a[]){
    int ct = 0, sum = 0;
    for (int i = 0; i < n; ++i){
        if (a[i] <= k){
            ct++;
            sum += a[i];
        }
    }
    printf("%d %d", ct, sum);
}