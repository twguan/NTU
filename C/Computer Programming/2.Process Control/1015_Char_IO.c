#include <stdio.h>

int main(){
    char a;
    scanf(" %c", &a);
    printf("%c\n", a);
    while (a != 'q'){
        scanf(" %c", &a);
        printf("%c\n", a);
    }
    return 0;
}