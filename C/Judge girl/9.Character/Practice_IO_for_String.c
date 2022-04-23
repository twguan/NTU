#include <stdio.h>
#include <ctype.h>
#include <string.h> //for gets()
int main(){
    char s[1000];
    gets(s); //gets() can get whole string until \n
    printf("input is:%s\n", s);
    
    return 0;
}