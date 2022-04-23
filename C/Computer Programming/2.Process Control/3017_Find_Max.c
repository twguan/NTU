#include <stdio.h>

int main(){
    int n = 0, index, sum = 0, max = 0, count = 1;
    double ave;
    scanf("%d", &n);
    while (n != -1){
        sum += n;
        ave = (double)sum/count;
        if (max < n){
            max = n;
            index = count;
        }
        count++;
        scanf("%d", &n);
    }
    printf("%d\n%.1f\n%d\n%d", sum, ave, max, index);
    return 0;
}