#include <stdio.h>
int ur(int up, int right, int row, int col, int arr[row][col]){
    if (!arr[up][right])
        return 0;
    if (up == 0 && right == (col-1))
        return 1;
    if (up == 0)
        return ur(up, right+1, row, col, arr);
    if (right == (col-1))
        return ur(up-1, right, row, col, arr);
    return (ur(up, right+1, row, col, arr) + ur(up-1, right, row, col, arr));
}
int main(){
    int row, col, i, j;
    scanf("%d%d", &row, &col);//row > up, col > right
    int arr[row][col];
    for (i = 0; i < row; ++i){
        for (j = 0; j < col; ++j)
            scanf("%d", &arr[i][j]);
    }
    printf("%d", ur(row-1, 0, row, col, arr));
    
}