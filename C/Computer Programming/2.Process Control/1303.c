#include <stdio.h>

int main(){
    int n, ct = 0;
    double sum = 0;
    while(1){
        scanf("%d", &n);
        if (n == -1)
            break;
        ct++;
        sum += n;
    }
    printf("%.0f\n%.1f", sum, sum/ct);
    return 0;
}