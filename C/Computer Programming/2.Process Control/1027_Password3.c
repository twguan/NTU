#include <stdio.h>
#include <string.h>

int main(){
    char password[101], input[101];
    scanf("%s", &password);
    scanf("%s", &input);
    while (strcmp(password, input)){
        printf("Wrong Password!\n");
        scanf("%s", input);
    }
    printf("Correct!");
    return 0;
}