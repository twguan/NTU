#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void back_print(char *str){
    int len = strlen(str);
    while (len)
        printf("%c", str[(len--)-1]);
}

int main(){
    int n, idx;
    scanf("%d", &n);
    char **ptr = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++)
        ptr[i] = (char *)malloc(sizeof(char *) * 8);
    
    for (int i = 0; i < n; i++)
        scanf("%s", ptr[i]);
    
    back_print(ptr[0]);

    for (int i = 1; i < n; i++){
        printf(" ");
        back_print(ptr[i]);
    }    
    printf("\n");
    scanf("%d", &idx);
    back_print(ptr[idx-1]);
    printf("\n");
    return 0;
}