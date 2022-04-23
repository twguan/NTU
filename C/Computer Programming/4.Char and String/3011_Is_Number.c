#include <stdio.h>
#include <ctype.h>

int main(){
    int a = 1;
    char c[5];
    gets(c);
    for (int i = 0; i < 1; ++i){
        if (c[i] == '\n')
            break;
        if (c[i] > '9' || c[i] < '0'){
            a = 0;
        }
    }
    if (a)
        printf("n=%s", c);
    else
        printf("is not a number");
    return 0;
}