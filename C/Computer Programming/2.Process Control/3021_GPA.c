#include <stdio.h>

int main(){
    int score;
    scanf("%d", &score);
    if (score >= 90)
        printf("4.3\nA+");
    else if (score >= 85)
        printf("4.0\nA");
    else if (score >= 80)
        printf("3.7\nA-");
    else if (score >= 77)
        printf("3.3\nB+");
    else if (score >= 73)
        printf("3.0\nB");
    else if (score >= 70)
        printf("2.7\nB-");
    else if (score >= 67)
        printf("2.3\nC+");
    else if (score >= 63)
        printf("2.0\nC");
    else if (score >= 60)
        printf("1.7\nC-");
    else
        printf("0\nF");
    return 0;
}