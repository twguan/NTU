#include <stdio.h>
#include <string.h>

int main(){
    char str[128];
    while (strncmp(gets(str), "-1", 3)){
        int len = strlen(str);
        for (int i = 0; i < len; ++i){
            char binary[8] = "0000000";
            int num = str[i], ct = 6;
            while (num){
                if (num % 2)
                    binary[ct] = '1';
                ct--;
                num /= 2;
            }
            printf("%s,", binary);
        }
        printf("\n");
    }
    return 0;
}