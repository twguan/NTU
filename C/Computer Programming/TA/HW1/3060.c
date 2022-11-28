#include <stdio.h>

int main(){
    int ct = 0, sum = 0, input, min = 9999, max = -1, midx, Midx;
    scanf("%d", &input);
    while(input != -1){
        ct++;
        sum += input;
        if (input < min){
            min = input;
            midx = ct;
        }
        if (input > max){
            max = input;
            Midx = ct;
        }
        scanf("%d", &input);
    }
    printf("%d\n%.1f\n%d\n%d\n%d\n%d", sum, (double)sum/ct, max, Midx, min, midx);
    return 0;
}