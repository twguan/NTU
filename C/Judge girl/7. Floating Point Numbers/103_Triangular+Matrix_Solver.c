#include <stdio.h>
int main(){
    int n, i, j, k;
    scanf("%d", &n);
    double A[n][n];
    double Ai[n][n];
    double y[n];
    for (i = 0; i < n; ++i){
        for (j = 0; j < n; ++j){
            scanf("%lf", &A[i][j]);
            Ai[i][j] = 0;
        }
        Ai[i][i] = 1;
    }
    for(i = 0; i < n; ++i)
        scanf("%lf", &y[i]);
    for (i = 0; i < n; ++i){
        double a = A[i][i];
        for (j = i; j < n; ++j)
            A[i][j] /= a;
        Ai[i][i] /= a;
    }
    for (j = n-1; j > 0; --j){
        for (i = j-1; i >= 0; --i){
            double a = A[i][j];
            for (k = 0; k < n; ++k)
                Ai[i][k] -= Ai[j][k]*a;
        }
    }
    for (i = 0; i < n; ++i){
        double sum = 0;
        for (j = 0; j < n; ++j)
            sum += Ai[i][j]*y[j];
        printf("%f\n", sum);
    }
    return 0;
}