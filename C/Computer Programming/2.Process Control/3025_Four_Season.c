#include <stdio.h>

int main(){
    int month;
    scanf("%d", &month);
    if (month > 12 || month < 1)
        printf("Month doesn't exist!");
    else if (month >= 3 && month <= 5)
        printf("Spring");
    else if (month >= 6 && month <= 8)
        printf("Summer");
    else if (month >= 9 && month <= 11)
        printf("Autumn");
    else 
        printf("Winter");
    return 0;
}