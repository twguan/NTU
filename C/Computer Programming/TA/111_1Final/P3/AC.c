#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "123.h"

int main(){
    int n;
    int board[8][8] = {};
    memset(board, 0, sizeof(board));
    scanf("%d", &n);
    int x, y;
    char op[8];
    place_queen(0, 0, 0);


    // for (int i = 0; i < 8; ++i){
    //     for (int j = 0; j < 8; ++j)
    //         printf("%d ", board[i][j]);
    //     printf("\n");
    // }
    return 0;
}