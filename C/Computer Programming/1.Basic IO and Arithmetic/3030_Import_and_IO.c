#include <stdio.h>
#include <math.h>

int main(){
    int score;
    double adj;
    scanf("%d", &score);
    adj = sqrt(score) * 10;
    printf("Original: %.2f\nAdjusted: %.2f(+%.0f)", (double)score, adj, adj - score);
    return 0;
}