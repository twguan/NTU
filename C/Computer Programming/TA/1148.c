#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int a, b, c;
    char arr[4][10] = {"\0"};
    char input[3];
    scanf(" %c", &input);
    while (input != '-'){
        scanf("%d%d%d", &a, &b, &c);
        if (a > b){
            if (a > c){
                int temp = a;
                a = c;
                c = a;
            }
        }
        else {
            if (b > c){
                int temp = b;
                b = c;
                c = temp;
            }
        }
        if (a+b <= c)
            strcat(arr[0], &input);
        else {
            a = a*a;
            b = b*b;
            c = c*c;
            if (a+b > c){ //obt
                strcat(arr[2], &input);
            }
            else if (a+b < c){
                strcat(arr[1], &input);
            }
            else{
                strcat(arr[3], &input);
            }
        }
        scanf(" %c", &input);
    }
    for (int i = 0; i < 4; i++)
        printf("len:%d\n", strlen(arr[i]));
    return 0;
}