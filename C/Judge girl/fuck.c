#include <stdio.h>

int main(){
    int a = 1;
    int b = 1;
    a += b << 2;
    printf("%d", a);
    return 0;
}