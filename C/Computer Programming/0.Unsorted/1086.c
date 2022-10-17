#include <stdio.h>
int count(int row, int col){
    if (row == 1 || col == 1)
        return 1;
    return count(row-1, col) + count(row, col-1);
}


int main(){
    int row, col;
    scanf("%d%d", &row, &col);
    printf("%d", count(row, col));
    return 0;
}