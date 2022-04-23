#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char s[102];
    int alpha[26] = {0};
    gets(s);
    for (int i = 0; i < strlen(s); ++i){
        s[i] = toupper(s[i]);
        if (isalpha(s[i]))
            alpha[s[i]-65]++;
    }
    for (int i = 0; i < 26; ++i)
        printf("%d\n", alpha[i]);
    return 0;
}