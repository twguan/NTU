#include <stdio.h>
#include <string.h>

int main(){
    char string[120], search[10];
    gets(string);
    gets(search);
    for (int i = 0; i < strlen(string); ++i){
        //if (string[i] == search[0]){
            if(!(strncmp(&string[i], search, strlen(search))))
                printf("%d\n", i);
        //}
    }
    return 0;
}