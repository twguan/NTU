#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, k, m, d, sum = 0;
    scanf("%d%d%d%d", &n, &k, &m, &d);
    int map[10][10] = {};
    int sub[10][10] = {};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &map[i][j]);
        
    for (int i = 0; i < k; i++){
        for (int j = 0; j < k; j++){
            scanf("%d", &sub[i][j]);
            sum += sub[i][j];
        }
    }
    int x = -1, y = -1;
    for (int i = 0; i < n-k+1; i++){
        for (int j = 0; j < n-k+1; j++){
            int m_sum = 0, ct = 0;
            for (int row = 0; row < k; row++){
                for (int col = 0; col < k; col++){
                    m_sum += map[i+row][j+col];
                    if (sub[row][col] != map[i+row][j+col])
                        ct++;
                }
            }
            if (abs(m_sum-sum) <= d && ct <= m){
                x = i;
                y = j;
            }
        }
    }
    printf("%d %d", x, y);
    return 0;
}