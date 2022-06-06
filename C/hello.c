#include <stdio.h>

int main(){
    char a[1][10];
    printf("%d %d", sizeof(char *), sizeof(a[0]));
    return 0;
}