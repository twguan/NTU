#include <stdio.h>
#include <stdlib.h>

int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    int **class = (int **)malloc(sizeof(int *) * m);
    double avg = 0;
    double cavg = 0;
    for (int i = 0; i < m; i++)
        class[i] = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < m; i++){
        printf("class %d\n", i+1);
        cavg = 0;
        for (int j = 0; j < n; j++){
            scanf("%d", &class[i][j]);
            printf(" %d: %d\n", j+1, class[i][j]);
            cavg += (double)class[i][j]/n;
        }
        printf(" avg: %.2lf\n", cavg);
        avg += cavg / m;
    }
    printf("avg: %.2lf", avg);

    for (int i = 0; i < m; i++)
        free(class[i]);
    free(class);
    return 0;
}