#include <stdio.h>

int main(){
    double pi = 3.1415926;
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    if (b > a) { //a>b
        double tmp = b;
        b = a;
        a = tmp;
    }
    if (c < b) {
        printf("%f", c*c*pi*3/4);
    }
    else if (c > a) {
        printf("%f", (c*c*3/4 + (c-a)*(c-a)/4 + (c-b)*(c-b)/4) * pi);
    }
    else {
        printf("%f", (c*c*3/4 + (c-b)*(c-b)/4) * pi);
    }
    return 0;
}