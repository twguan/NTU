#include <stdio.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2){
    return(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}
int main(){
    double x1, x2, x3, y1, y2, y3, s;
    scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
    double l1 = distance(x1, y1, x2, y2);
    double l2 = distance(x2, y2, x3, y3);
    double l3 = distance(x1, y1, x3, y3);
    s = (l1 + l2 + l3) / 2;
    if (l3 >= l1 + l2 || l2 >= l1 + l3 || l1 >= l2 + l3)
        printf("0.00");
    else {
        printf("%.2f", sqrt(s * (s - l1) * (s - l2) * (s - l3)));
    }
    return 0;
}