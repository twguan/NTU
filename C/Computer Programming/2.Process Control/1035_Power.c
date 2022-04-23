#include <stdio.h>

int main(){
    int n, i, sum;
    scanf("%d%d", &n, &i);
    sum = n;
    for (int j = 1; j < i; ++j)
        sum *= n;
    printf("%d", sum);
    return 0;
}