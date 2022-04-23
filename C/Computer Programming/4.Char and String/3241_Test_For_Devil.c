#include <stdio.h>

int main(){
    int n, i, j, k, array[500], l, r, ct = 0;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &array[i]);
    for (i = 0; i < n-1; ++i){
        l = array[i];
        for (j = i+1; j < n; ++j){
            r = array[j];
            if (j - i > 1)
                l = l ^ array[j-1];
            if (l == r){
                printf("(i: %d,j: %d,k: %d)\n", i, j, j);
                ct++;
            }
            for (k = j+1; k < n; ++k){
                r = r ^ array[k];
                if (l == r){
                    printf("(i: %d,j: %d,k: %d)\n", i, j, k);
                    ct++;
                }
            }
        }
    }
    printf("%d", ct);
    return 0;
}