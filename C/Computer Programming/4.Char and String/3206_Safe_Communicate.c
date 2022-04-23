#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d%c", &n);
    char s[500], c;
    gets(s);
    for (int i = 0; i < strlen(s); ++i){
        if(s[i] >= 65 && s[i] <= 90){
            s[i] = s[i] - 65 - n % 26 + 65;
            if (s[i] < 65)
                s[i] += 26;
        }
        else if(s[i] >= 97 && s[i] <= 122){
            s[i] = s[i] - 97 - n % 26 + 97;
            if (s[i] < 97)
                s[i] += 26;
        }
    }
    puts(s);
    return 0;
}