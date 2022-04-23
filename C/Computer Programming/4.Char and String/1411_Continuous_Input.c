#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int numint = 0, numfloat = 0;
    char input[10];
    gets(input);
    while (strncmp(input, "q", 1)){
        if(isdigit(input[0]) || input[0] == '-'){
            numint++;
            for (int i = 0; i < strlen(input); ++i){
                if (input[i] == '.'){
                    numint--;
                    numfloat++;
                }
            }
        }
        gets(input);
    }
    printf("%d\n%d", numfloat, numint);
    return 0;
}