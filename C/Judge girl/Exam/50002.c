#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, k;

    scanf("%d%d", &n, &k);

    int map[n+2][n+2];
    int calculate[n+2][n+2];
    int final[n+2][n+2];
    for (int i = 0; i < n+2; i++){
        for (int j = 0; j < n+2; j++){
            map[i][j] = 0;
            calculate[i][j] = 0;
            final[i][j] = 0;
        }
    }

    for (int i = 1; i < n+1; i++)
        for (int j = 1; j < n+1; j++){
            scanf("%d", &map[i][j]);
            final[i][j] = map[i][j];
        }

    for (int l = 0; l < k; l++){
        for (int i = 1; i < n+1; i++){
            for (int j = 1; j < n+1; j++){
                int sum = 0;
                sum += map[i-1][j-1];
                sum += map[i-1][j];
                sum += map[i-1][j+1];
                sum += map[i][j-1];
                sum += map[i][j+1];
                sum += map[i+1][j-1];
                sum += map[i+1][j];
                sum += map[i+1][j+1];
                calculate[i][j] = sum;
            }
        }
        for (int i = 1; i < n+1; i++){
            for (int j = 1; j < n+1; j++){
                if (map[i][j] == 1){
                    if (calculate[i][j] == 2 || calculate[i][j] == 3)
                        map[i][j] = 1;
                    else
                        map[i][j] = 0;
                }
                else{
                    if (calculate[i][j] == 3)
                        map[i][j] = 1;
                }
                final[i][j] += map[i][j];
            }
        }
    }
    // printf("\n");
    // for (int i = 1; i < n+1; i++){
    //     for (int j = 1; j < n+1; j++)
    //         printf("%d ", calculate[i][j]);
    //     printf("\n");
    // }
    // printf("\n");
    int x = 0, y = 0, ct = 0; 
    for (int i = 1; i < n+1; i++){
        for (int j = 1; j < n+1; j++){
            if (final[i][j] >= ct){
                x = i;
                y = j;
                ct = final[i][j];
            }
            if (j == 1)
                printf("%d", map[i][j]);
            else
                printf(" %d", map[i][j]);
        }
        printf("\n");
    }
    printf("%d %d", x, y);
    // for (int i = 1; i < n+1; i++){
    //     for (int j = 1; j < n+1; j++)
    //         printf("%d ", final[i][j]);
    //     printf("\n");
    // }
    return 0;
}