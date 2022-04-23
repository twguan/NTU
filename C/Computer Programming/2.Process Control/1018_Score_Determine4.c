#include <stdio.h>

int main(){
    int score;
    char y;
    do {
        scanf("%d", &score);
        if (score >= 60)
            printf("pass\n");
        else
            printf("fail\n");
        scanf(" %c", &y);
    } while (y == 'y');
    return 0;
}