#include <stdio.h>
#include <math.h>

int main(){
    int sum, a, b, i, n = 1000;
    double c, ave, sd;
    scanf("%d%d%lf", &a, &b, &c);
    for (i = 0; i < 4; ++i){
        sum = a / n % 10 + b / n % 10 + (int)c / n % 10;
        ave = sum / 3.0;
        sd = pow(a/n%10 - ave, 2)+pow(b/n%10 - ave, 2)+pow((int)c/n%10 - ave, 2);
        sd = sqrt(sd / 3);
        printf("%d %.2f %.2f\n", sum, ave, sd);
        n /= 10;
    }
    double asum = a + b + c;
    ave = asum / 3;
    sd = pow((a - ave), 2)+pow((b - ave), 2)+pow((c - ave), 2);
    sd = sqrt(sd / 3);
    printf("%.2f %.2f %.2f", asum, ave, sd);
    return 0;
}