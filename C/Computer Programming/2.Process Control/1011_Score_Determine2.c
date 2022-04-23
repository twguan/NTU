#include <stdio.h>

int main(){
    int isResearch, score, std = 60;
    scanf("%d%d", &isResearch, &score);
    if (isResearch - 1)
        std = 70;
    if (score >= std)
        printf("pass");
    else
        printf("fail");
    return 0;
}