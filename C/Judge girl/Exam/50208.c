#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int include(char *code, char *str, int mode){
    int n1 = strlen(code), n2 = strlen(str), n;
    if (n1 > n2)
        n = n2;
    else
        n = n1;
    // care space
    if (mode){
        if (n1 == n2 && !strcmp(code, str))
            return 1;
        else
            return 0;
    }
    else{
        for (int i = 0; i < n1-n2+1; i++)
            if (!strncmp(code+i, str, n))
                return 1;
    }
    return 0;
}


int main(){
    int ct = 0;
    char code[100000];
    char *d = " ()";
    while (gets(code)){
        int i=0;
        while(*(code+i) == '\t' || *(code+i) == ' ')
            i++;
        char *ptr = strtok(code+i, d);
        while (ptr != NULL){
            // printf("%s\n", ptr);
            if (include(ptr, "if", 1) || include(ptr, "for", 1) || include(ptr, "?", 0) || include(ptr, "case", 1) || include(ptr, "while", 1)){
                // printf("%d: %s\n", ct+1, ptr);
                ct++;
            }
            ptr = strtok(NULL, d);
        }
    }
    printf("%d", ct);
    return 0;
}