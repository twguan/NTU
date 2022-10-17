#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n, input;
    scanf("%d", &n);
    char **ptr = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++)
        ptr[i] = (char *)malloc(sizeof(char) * 64);
    
    for (int i = 0; i < n; i++)
        scanf("%s", ptr[i]);

    while (scanf("%d", &input) != EOF)
        printf("%s\n", ptr[input]);
    return 0;
}