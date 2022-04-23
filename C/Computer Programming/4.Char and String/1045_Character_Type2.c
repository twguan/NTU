#include <stdio.h>

int main(){
    char c;
    scanf(" %c", &c);
    if (c >= 97 && c <= 122){
        printf("%c is a lowercase letter.\n");
        printf("swap to capital letter %c.", c - 32);
    }
    else if (c >= 65 && c <= 90)
        printf("%c is a capital letter.", c);
    else if (c >= 48 && c <= 57)
        printf("%c is a number.", c);
    else
        printf("%c is a punctuation.");
    return 0;
}