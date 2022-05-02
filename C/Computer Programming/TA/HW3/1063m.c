#include <stdio.h>
#include <stdlib.h>
#include "score.h"

int main(){
    int n;
    scanf("%d", &n);
    int *P = (int *)malloc(sizeof(int) * n);
    inputAry(n, P);
    printf("avg = %.2f\n", Avg(n, P));
    printf("%d", MaxScore(n, P));
    return 0;
}