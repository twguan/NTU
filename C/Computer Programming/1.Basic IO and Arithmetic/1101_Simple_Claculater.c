#include <stdio.h>

int main(){
    double a, b;
    scanf("%lf%lf", &a, &b);
    printf("%.2f + %.2f = %.2f\n", a, b, a+b);
    printf("%.2f - %.2f = %.2f\n", a, b, a-b);
    printf("%.2f * %.2f = %.2f\n", a, b, a*b);
    printf("%.2f / %.2f = %.2f\n", a, b, a/b);
    return 0;
}