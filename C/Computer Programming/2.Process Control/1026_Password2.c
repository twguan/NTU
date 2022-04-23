#include <stdio.h>

int main(){
    int password, input;
    scanf("%d", &password);
    if (password > 2000000000 || password < 0)
        printf("Wrong Password Setting!");
    else {
        scanf("%d", &input);
        while (input != password){
            printf("Wrong Password!\n");
            scanf("%d", &input);
        }
        printf("Correct!");
    }
    return 0;
}