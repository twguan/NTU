#include <stdio.h>

int main(){
    char a;
    scanf(" %c", &a);
    while (a == 'y'){
        printf("run\n");
        scanf(" %c", &a);
    }
}