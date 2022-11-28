#include <stdio.h>
#include <string.h>

int main(){

    char string[64] = "abc defg hi123";
    char c[3][6];
    const char *s = " ";
    char *token;
    token = strtok(string, s);
    int i = 0;
    while (token != NULL){
        /* do .... */
        // strncpy(c[i++], token, strlen(token));
        token = strtok(NULL, s);
    }
    // printf("c1:%s c2:%s c3:%s\n", c[0], c[1], c[2]);
    return 0;
}
