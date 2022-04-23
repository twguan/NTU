#include <stdio.h>
#include <string.h>

int main(){
    char s[120], search[10];
    gets(s);
    gets(search);
    for (int i = 0; i < strlen(s); ++i){
        if(!(strncmp(&s[i], search, strlen(search)))){

            printf("%d\t%c%c+%s+%c%c\n", i, s[i-2], s[i-1], search, s[i+strlen(search)], s[i+strlen(search)+1]);
        }
    }
    return 0;
}