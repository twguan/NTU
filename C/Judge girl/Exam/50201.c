#include <stdio.h>

int main(){
    int map[601][601], row, col, start=0;
    scanf("%d%d", &row, &col);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &map[i][j]);

    int op;
    while (scanf("%d", &op) != EOF){
        int k;
        scanf("%d", &k);
        if (op == 1){
            // down
            for (int i = 0; i < k; i++)
                for (int j = 0; j < col; j++)
                    map[start+2*k-1-i][j] += map[start+i][j];

            start += k;
        }
        else if (op == 2){
            // left
            for (int j = 0; j < k; j++)
                for (int i = start; i < row; i++)
                    map[i][col-2*k+j] += map[i][col-j-1];
            col -= k;
        }
        else if (op == 3){
            // diagonal
            for (int i = 0; i < k; i++)
                for (int j = i; j < k; j++){
                    if (i != j){
                        map[start+j][col-k+i] += map[start+i][col-k+j];
                        map[start+i][col-k+j] = 0;
                        // map[start+j][col-k+i] = 0;
                    }
                }
        }
    }
    for (int i = start; i < row; i++){
        for (int j = 0; j < col; j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }
    return 0;
}