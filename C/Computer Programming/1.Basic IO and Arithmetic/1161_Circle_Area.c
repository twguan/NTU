#include <stdio.h>

int main(){
    double a, b, c, pi = 3.1415926, sum = 0;
    scanf("%lf%lf%lf", &a, &b, &c);
    sum += c * c * 3;
    if (c > b)
        sum += (c - b) * (c - b);
    if (c > a)
        sum += (c - a) * (c - a);
    printf("%f", sum * pi / 4);
    return 0;
}