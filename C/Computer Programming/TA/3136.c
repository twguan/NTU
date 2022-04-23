#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n, num;
    scanf("%d", &n);
    char **id = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++){
        id[i] = (char *)malloc(sizeof(char) * 8);
        scanf("%s", id[i]);
    }
    scanf("%d", &num);
    for (int j = strlen(id[0])-1; j >= 0; j--)
        printf("%c", id[0][j]);
    for (int i = 1; i < n; i++){
        printf(" ");
        for (int j = strlen(id[i])-1; j >= 0; j--)
            printf("%c", id[i][j]);  
    }
    printf("\n");
    for (int j = strlen(id[num-1])-1; j >= 0; j--)
        printf("%c", id[num-1][j]);
    printf("\n");
    return 0;
}