#include <stdio.h>

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a + b > c && a + c > b && b + c > a){
        printf("True\n");
        if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a)
            printf("Right Triangle");
        else
            printf("Non-Right Triangle");
    }
    else
        printf("False");
    return 0;
}