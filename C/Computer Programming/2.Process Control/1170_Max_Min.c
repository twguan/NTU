#include <stdio.h>

int main(){
    int n, max = 0, min = 1000000, temp, maxp, minp, maxp2 = 0, minp2 = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &temp);
        if (temp >= max){
            if (temp == max)
                maxp2 = i;
            else {
                max = temp;
                maxp = i;
                maxp2 = 0;
            }
        }
        if (temp <= min){
            if (temp == min)
                minp2 = i;
            else {
                min = temp;
                minp = i;
                minp2 =0;
            }
        }
    }
    printf("%d %d", max, maxp);
    if (maxp2)
        printf(" %d", maxp2);
    printf("\n%d %d", min, minp);
    if (minp2)
        printf(" %d", minp2);
    return 0;
}