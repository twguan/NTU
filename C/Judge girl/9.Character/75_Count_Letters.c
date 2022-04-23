#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    int i, num[26] = {0};
    char a;
    while (scanf("%c", &a) != EOF){
        if (isupper(a)){
            num[a - 'A']++;
        }
        else if (islower(a))
            num[a - 'a']++;
        else 
            continue;
    }
    for (i = 0; i < 26; ++i)
        printf("%d\n", num[i]);
    return 0;
}