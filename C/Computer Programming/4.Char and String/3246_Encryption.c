#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char size[10], de;
    gets(size);
    int row, col;
    row = size[0] - 47;
    col = size[2] - 47;
    char code[10][10], password[200], output[200];
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            if (i == 0 && j == 0)
                continue;
            scanf(" %c", &code[i][j]);
        }
    }
    scanf(" %c", &de);
    if (de - 68){//en
        char a;
        int ct = 0;
        while (scanf(" %c", &a) != EOF){
            for (int i = 1; i < row; ++i){
                for (int j = 1; j < col; ++j){
                    if (a == code[i][j]){
                        output[ct] = code[i][0];
                        output[ct+1] = code[0][j];
                        ct += 2;
                    }
                }
            }
        }
        printf("%d\n", ct);
        for (int i = 0; i < ct; ++i)
            printf("%c", output[i]);
    }
    else {
        char a, b;
        int ct = 0, x, y;
        while (scanf(" %c %c", &a, &b) != EOF){
            for (int i = 0; i < row; ++i){
                if (a == code[i][0]){
                    x = i;
                    break;
                }
            }
            for (int i = 0; i < col; ++i){
                if (b == code[0][i]){
                    y = i;
                    break;
                }
            }
            output[ct] = code[x][y];
            ct++;
        }
        printf("%d\n", ct);
        for (int i = 0; i < ct; ++i)
            printf("%c", output[i]); 
    }
    return 0;
}