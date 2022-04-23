#include <stdio.h>
int ur(int up, int right){
    if (up == 0 || right == 0)
        return 1;
    return (ur(up, right-1) + ur(up-1, right));
}
int main(){
    int row, col;
    scanf("%d%d", &row, &col);//row > up, col > right
    row -= 1;
    col -= 1;
    printf("%d", ur(row, col));
}