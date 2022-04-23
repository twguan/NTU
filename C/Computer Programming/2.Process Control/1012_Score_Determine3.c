#include <stdio.h>

int main(){
    int isResearch, score, std = 60;
    scanf("%d", &isResearch);
    if (isResearch > 2 || isResearch < 1)
        printf("role error");
    else {
        scanf("%d", &score);
        if (score > 100 || score < 0)
            printf("score error");
        else {
            if (isResearch - 1)
                std = 70;
            if (score >= std)
                printf("pass");
            else
                printf("fail");
        }
    }
    return 0;
}