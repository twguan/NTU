#include <stdio.h>

int main(){
    int top, bot, h;
    scanf("%d%d%d", &top, &bot, &h);
    printf("%.1f", (top + bot) * h / 2.0);
    return 0;
}