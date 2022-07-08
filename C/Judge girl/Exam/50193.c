#include <stdio.h>
#include <stdlib.h>

int toSec(int time){
    int sec = (time / 10000) * 3600;
    sec += (time % 10000 / 100 * 60) + time % 100;
    return sec;
}

int main(){
    int time1 = 0, time2 = 0, diff = 999999, sec1, sec2;
    scanf("%d", &time1);
    sec1 = toSec(time1);
    while (scanf("%d", &time2) != EOF){
        sec2 = toSec(time2);
        if (abs(sec2 - sec1) < diff)
            diff = abs(sec2 - sec1);
        sec1 = sec2;
    }

    printf("%d", diff);
    return 0;
}