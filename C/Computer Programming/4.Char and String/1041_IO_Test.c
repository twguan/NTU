#include <stdio.h>

int main(){
    char c, s1[20], s2[20];
    scanf("%c", &c);
    scanf("%s ", s1);
    gets(s2);
    putchar(c);
    putchar('\n');
    puts(s1);
    puts(s2);
    return 0;
}