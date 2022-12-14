#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chess.h"

int main(){
    int n;
    int board[8][8] = {};
    memset(board, 0, sizeof(board));
    scanf("%d", &n);
    int x, y;
    char op[8];
    for (int i = 0; i < n; ++i){
        scanf("%s", op);
        if (!strcmp(op, "queen")){
            scanf("%d%d", &x, &y);
            place_queen(board, x, y);
        }
        else if (!strcmp(op, "rook")){
            scanf("%d%d", &x, &y);
            place_rook(board, x, y);
        }
        else if (!strcmp(op, "bishop")){
            scanf("%d%d", &x, &y);
            place_bishop(board, x, y);
        }
        else if (!strcmp(op, "knight")){
            scanf("%d%d", &x, &y);
            place_knight(board, x, y);
        }
        else if (!strcmp(op, "count")){
            count_chess(board);
        }
        else if (!strcmp(op, "print")){
            for (int i = 0; i < 8; ++i){
                for (int j = 0; j < 8; ++j)
                    printf("%3d", board[i][j]);
                printf("\n");
            }
            printf("\n");
        }
    }
    return 0;
}