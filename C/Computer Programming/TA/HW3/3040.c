#include <stdio.h>

void year(int t, int d){
    switch (t){
    case 0:
        printf("甲");
        break;
    case 1:
        printf("乙");
        break;
    case 2:
        printf("丙");
        break;
    case 3:
        printf("丁");
        break;
    case 4:
        printf("戊");
        break;
    case 5:
        printf("己");
        break;
    case 6:
        printf("庚");
        break;
    case 7:
        printf("辛");
        break;
    case 8:
        printf("壬");
        break;
    case -1:
        printf("癸");
        break;
    }
    switch (d){
    case 0:
        printf("子");
        break;
    case 1:
        printf("丑");
        break;
    case 2:
        printf("寅");
        break;
    case 3:
        printf("卯");
        break;
    case 4:
        printf("辰");
        break;
    case 5:
        printf("巳");
        break;
    case 6:
        printf("午");
        break;
    case 7:
        printf("未");
        break;
    case 8:
        printf("申");
        break;
    case 9:
        printf("酉");
        break;
    case 10:
        printf("戌");
        break;
    case -1:
        printf("亥");
        break;
    }
    printf("年\n");
}
int main(){
    int temp, t, d;
    while(scanf("%d", &temp) != 0){
        printf("%d = ", temp);
        t = (temp - 3) % 10 - 1;
        d = (temp - 3) % 12 - 1;
        year(t, d);
    }
    return 0;
}