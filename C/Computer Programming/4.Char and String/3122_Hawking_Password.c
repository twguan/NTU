#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char input[300];
    gets(input);
    for (int i = 0; i < strlen(input); i++){
        if (isdigit(input[i])){
            if (input[i] == '1')
                input[i] = 'I';
            else if (input[i] == '7')
                input[i] = 'T';
            else if (input[i] == '3')
                input[i] = 'E';
            else if (input[i] == '5')
                input[i] = 'S';
            else if (input[i] == '4')
                input[i] = 'A';
            else if (input[i] == '0')
                input[i] = 'O';
        }
    }
    puts(input);
    return 0;
}