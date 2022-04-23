#include <stdio.h>

int main(){
    int head, feet, chicken, rabbit;
    scanf("%d%d", &head, &feet);
    rabbit = feet / 2 - head;
    chicken = head - rabbit;
    if (rabbit < 0 || chicken < 0 || feet % 2 != 0)
        printf("NO\n");
    else
        printf("YES\n%d %d\n", chicken, rabbit);
    return 0;
}