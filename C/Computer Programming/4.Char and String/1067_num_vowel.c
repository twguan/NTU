#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int num = 0, vowel = 0, cons = 0;
    char s[1000];
    gets(s);
    for (int i = 0; i < strlen(s); ++i){
        s[i] = toupper(s[i]);
        if (isdigit(s[i]))
            num++;
        else if (isalpha(s[i])){
            if (s[i]==65 || s[i]==69 || s[i]==73 || s[i]==79 || s[i]==85)
                vowel++;
            else
                cons++;
        }
    }
    printf("%d %d %d %d", num, vowel+cons, vowel, cons);
    return 0;
}