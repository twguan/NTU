#include <stdio.h>

int main(){
    int max = 0, max2 = 0, max3 = 0, temp;
    scanf("%d", &temp);
    while (temp != -1){
        if (temp >= max){
            max3 = max2;
            max2 = max;
            max = temp;
        }
        else if (temp >= max2){
            max3 = max2;
            max2 = temp;
        }
        else if (temp >= max3)
            max3 = temp;
        scanf("%d", &temp);
    }
    int bag = max + max3, count = 1, ans = 0;
    while (bag){
        ans += (bag % 7) * count;
        bag /= 7;
        count *= 10;
    }
    printf("%d", ans);
    return 0;
}