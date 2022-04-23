#include <stdio.h>
#include <string.h>

int main(){
    int year;
    char type[8];
    char ad[] = "AD";
    scanf("%s", type);
    scanf("%d", &year);
    while (year != -1){
        if (!strcmp(type, ad))
            year = year % 12;
        else
            year = (year + 1911) % 12;
        switch (year){
        case 4:
            printf("鼠\n");
            break;
        case 5:
            printf("牛\n");
            break;
        case 6:
            printf("虎\n");
            break;
        case 7:
            printf("兔\n");
            break;
        case 8:
            printf("龍\n");
            break;
        case 9:
            printf("蛇\n");
            break;
        case 10:
            printf("馬\n");
            break;
        case 11:
            printf("羊\n");
            break;
        case 0:
            printf("猴\n");
            break;
        case 1:
            printf("雞\n");
            break;
        case 2:
            printf("狗\n");
            break;
        case 3:
            printf("豬\n");
            break;
        }
        scanf("%d", &year);
    }    
    return 0;
}