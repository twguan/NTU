#include <stdio.h>

int main(){
    int score[3], i, high = 0, num;
    double ave;
    for (i = 0; i < 3; ++i){
        scanf("%d", &score[i]);
        ave += score[i];
    }
    printf("avg = %.2f\nfail:\n", ave / 3);
    for (i = 0; i < 3; ++i){
        if (score[i] > high){
            high = score[i];
            num = i + 1;
        }
        if (score[i] < 60)
            printf("%d: %d\n", i+1, score[i]);
    }
    printf("highest:\n%d: %d", num, high);
    return 0;
}