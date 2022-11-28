#include <stdio.h>

int main(){
    // n: pigeons  m: holes
    int n, m;
    scanf("%d%d", &n, &m);
    printf("p cnf %d %d\n", n * m,n + m * m * (n - (m + 1) / 2));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++)
            printf("%d ", m * (i-1)+j);
        printf("0\n");
    }

    for (int j = 1; j <= m; j++)
        for (int i = 1; i <= m; i++) 
            for (int k = i+1; k <= n; k++)
                printf("-%d -%d 0\n", m*(i-1)+j, m*(k-1)+j);
    return 0;
}