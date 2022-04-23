#include <stdio.h>

int main(){
    int row, col, sum;
    scanf("%d%d", &row, &col);
    int ay[row][col];
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            scanf("%d", &ay[i][j]);
    for (int j = 0; j < col; ++j){
        sum = 0;
        for (int i = 0; i < row; ++i){
            sum += ay[i][j];
        }
        printf("%d\n", sum / row);
    }
            
}