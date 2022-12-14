#include <stdio.h>
#include "chess.h"
void place_queen(int board[8][8], int x, int y){
    if (board[x][y] == -1 || board[x][y] == 4){
        printf("invalid place\n");
        return;
    }
    if (board[x][y] == 1){
        if (x > 0){
            if (y > 1)
                board[x-1][y-2] = 0;
            if (y < 6)
                board[x-1][y+2] = 0;
        }
        if (x < 7){
            if (y > 1)
                board[x+1][y-2] = 0;
            if (y < 6)
                board[x+1][y+2] = 0;
        }
        if (y > 0){
            if (x > 1)
                board[x-2][y-1] = 0;
            if (x < 6)
                board[x+2][y-1] = 0;
        }
        if (y < 7){
            if (x > 1)
                board[x-2][y+1] = 0;
            if (x < 6)
                board[x+2][y+1] = 0;
        }
    }

    for (int i = 0; i < 8; i++){
        if (board[i][y] < 1)
            board[i][y] = -1;
        if (board[x][i] < 1)
            board[x][i] = -1;
        if (x-i >= 0 && y-i >= 0 && board[x-i][y-i] < 1)
            board[x-i][y-i] = -1;
        if (x+i < 8 && y+i < 8 && board[x+i][y+i] < 1)
            board[x+i][y+i] = -1;
        if (x-i >= 0 && y+i < 8 && board[x-i][y+i] < 1)
            board[x-i][y+i] = -1;
        if (x+i < 8 && y-i >= 0 && board[x+i][y-i] < 1)
            board[x+i][y-i] = -1;
    }
    board[x][y] = 4;
}

void place_rook(int board[8][8], int x, int y){
    if (board[x][y] != 0){
        printf("invalid place\n");
        return;
    }
    for (int i = 0; i < 8; ++i){
        if (board[i][y] < 1)
            board[i][y] = -1;
        if (board[x][i] < 1)
            board[x][i] = -1;
    }
    board[x][y] = 3;
}

void place_bishop(int board[8][8], int x, int y){
    if (board[x][y] != 0){
        printf("invalid place\n");
        return;
    }
    for (int i = 0; i < 8; i++){
        if (x-i >= 0 && y-i >= 0 && board[x-i][y-i] < 1)
            board[x-i][y-i] = -1;
        if (x+i < 8 && y+i < 8 && board[x+i][y+i] < 1)
            board[x+i][y+i] = -1;
        if (x-i >= 0 && y+i < 8 && board[x-i][y+i] < 1)
            board[x-i][y+i] = -1;
        if (x+i < 8 && y-i >= 0 && board[x+i][y-i] < 1)
            board[x+i][y-i] = -1;
    }
    board[x][y] = 2;
}

void place_knight(int board[8][8], int x, int y){
    if (board[x][y] != 0){
        printf("invalid place\n");
        return;
    }
    if (x > 0){
            if (y > 1 && board[x-1][y-2] < 1)
                board[x-1][y-2] = -1;
            if (y < 6 && board[x-1][y+2] < 1)
                board[x-1][y+2] = -1;
        }
        if (x < 7){
            if (y > 1 && board[x+1][y-2] < 1)
                board[x+1][y-2] = -1;
            if (y < 6 && board[x+1][y+2] < 1)
                board[x+1][y+2] = -1;
        }
        if (y > 0){
            if (x > 1 && board[x-2][y-1] < 1)
                board[x-2][y-1] = -1;
            if (x < 6 && board[x+2][y-1] < 1)
                board[x+2][y-1] = -1;
        }
        if (y < 7){
            if (x > 1 && board[x-2][y+1] < 1)
                board[x-2][y+1] = -1;
            if (x < 6 && board[x+2][y+1] < 1)
                board[x+2][y+1] = -1;
        }
        board[x][y] = 1;
}

void count_chess(int board[8][8]){
    int q = 0, r = 0, b = 0, k = 0;
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            if (board[i][j] == 4)
                q++;
            else if (board[i][j] == 3)
                r++;
            else if (board[i][j] == 2)
                b++;
            else if (board[i][j] == 1)
                k++;
        }
    }
    printf("#queen:%2d\n#rook:%2d\n#bishop:%2d\n#knight:%2d\n\n", q, r, b, k);
}