#include <stdio.h>

int main(){
    int a, b, c, sum, pro, small, large;
    double ave;
    scanf("%d%d%d", &a, &b, &c);
    sum = a + b + c;
    ave = sum / 3.0;
    pro = a * b * c;
    if (a > b){
        if (c > a){
            large = c;
            small = b;
        }
        else {
            large = a;
            small = b;
            if (c < b);
                small = c;
        }
    }
    else {
        if (c > b){
            large = c;
            small = a;
        }
        else {
            large = b;
            small = a;
            if (c < a)
                small = c;
        }
    }
    printf("sum is %d\naverage is %.2f\nproduct is %d\nsmallest is %d\nlargest is %d", sum, ave, pro, small, large);
    return 0;
}