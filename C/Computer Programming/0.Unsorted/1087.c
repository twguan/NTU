#include <stdio.h>

int map[16][16];
int r, c;

int count(int row, int col){
    if (row == 0 && col == c-1)
        return 1;

    if (row > 0 && col < c-1 && map[row-1][col] && map[row][col+1])
        return count(row-1, col) + count(row, col+1);
    else if (map[row-1][col] && row > 0)
        return count(row-1, col);
    else if (map[row][col+1] && col < c-1)
        return count(row, col+1);
    else
        return 0;
}

int main(){
    int ct = 0;
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &map[i][j]);
    printf("%d", count(r-1, 0));
    return 0;
}