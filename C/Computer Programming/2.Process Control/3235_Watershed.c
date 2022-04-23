#include <stdio.h>
#include <math.h>

int main(){
    int n, i, max1, max2 = 0, temp, area = 0, pos1 = 1, pos2, ct = 0;
    scanf("%d", &n);
    scanf("%d", &max1);
    for (i = 2; i <= n; ++i){
        scanf("%d", &temp);
        if (temp > max1){
            max2 = max1;
            pos2 = pos1;
            max1 = temp;
            pos1 = i;
            ct = 0;
        }
        else if (temp == max2){
            if (temp == max1){
                if (abs(pos2 - pos1) < ct){
                    pos1 = i-ct;
                    pos2 = i;
                }
                ct = 0;
            }            
        }
        else if (temp > max2){
            if (temp == max1)
                ct = 0;
            max2 = temp;
            pos2 = i;
        }
        ct++;
    }
    area = max2 * abs(pos1 - pos2);
    if (pos1 > pos2){
        temp = pos1;
        pos1 = pos2;
        pos2 = temp;
    }
    printf("%d %d\n%d", pos1, pos2, area);
    return 0;
}