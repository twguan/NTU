#include <stdio.h>
#include <ctype.h>
#include <string.h>
 
int main(){
    char s[20];
    gets(s);
    for(int i = 0; i < strlen(s); ++i){
        if (isalpha(s[i])){
            s[i] = tolower(s[i])-3;
            if (s[i] < 'a')
                s[i] += 26;
            }
    }
    printf("%s", s);
    gets(s);
    while (strncmp(s, "-1", 2)){
        for(int i = 0; i < strlen(s); ++i){
            if (isalpha(s[i])){
                s[i] = tolower(s[i])-3;
                if (s[i] < 'a')
                    s[i] += 26;
            }
        }
            printf(" %s", s);
            gets(s);
    }   
    return 0;
}