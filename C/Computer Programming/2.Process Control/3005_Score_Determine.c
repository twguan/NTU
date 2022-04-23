#include <stdio.h>

int main(){
    int score;
    scanf("%d", &score);
    if (score >= 60)
        printf("pass");
    else
        printf("fail");
    return 0;
}