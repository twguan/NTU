#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    int n, sum = 0, max = 0;
    char s[15], ans[15];
    scanf("%d ", &n);
    for (int i = 0; i < n; ++i){
        sum = 0;
        scanf("%s", s);
        for (int j = 0; j < strlen(s); ++j){
            s[j] = toupper(s[j]);
            sum += s[j] - 64;
        }
        printf("%s = %d\n", s, sum);
        if (sum > max){
            max = sum;
            strcpy(ans, s);
        }
    }
    printf("%s is the key.", ans);
    return 0;
}