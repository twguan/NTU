#include <stdio.h>

typedef struct Score{
    int math, eng, cmp;
} Score;

int main(){
    int cmd, ct = 0, num;
    scanf("%d", &cmd);
    Score class[5];
    double avemath = 0, avecmp = 0, aveeng = 0, ave;
    while(cmd){
        switch (cmd){
        case 1:
            scanf("%d\n", &class[ct].math);
            scanf("%d\n", &class[ct].eng);
            scanf("%d\n", &class[ct].cmp);
            ct++;
            break;
        case 2:
            scanf("%d", &num);
            printf("%d\n", class[num-1].math);
            printf("%d\n", class[num-1].eng);
            printf("%d\n", class[num-1].cmp);
            break;
        case 3:
            scanf("%d", &num);
            scanf("%d\n", &class[num-1].math);
            scanf("%d\n", &class[num-1].eng);
            scanf("%d\n", &class[num-1].cmp);
            break;
        case 4:
            for (int i = 0; i < ct; ++i){
                printf("%d\n", class[i].math);
                printf("%d\n", class[i].eng);
                printf("%d\n", class[i].cmp);
            }
            break;
        case 5:
            for (int i = 0; i < ct; ++i){
                avemath += class[i].math;
                aveeng += class[i].eng;
                avecmp += class[i].cmp;
            }
            printf("%.2f\n", avemath / ct);
            printf("%.2f\n", aveeng / ct);
            printf("%.2f\n", avecmp / ct);
            break;
        case 6:
            scanf("%d", &num);
            ave = class[num-1].math + class[num-1].eng + class[num-1].cmp;
            printf("%.2f\n", ave / 3);
            break;
        }
        scanf("%d", &cmd);
    }
    return 0;
}