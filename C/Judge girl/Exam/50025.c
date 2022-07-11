#include <stdio.h>
#include <stdlib.h>

void relation(int map[101][101], int ans[], int ct, int n, int m, int p){
    if (ct == m){
        for (int i = 0; i < m; i++)
            printf("%d ", ans[i]);
        exit(0);
    }
    for (int i = p; i < n; i++){
        for (int j = i; i < n; j++){
            int go = 1;
            if (!map[i][j]){
                for (int k = 0; k < ct; k++){
                    if (map[ans[k]][j] || ans[k] == j){
                        go = 0;
                        break;
                    }
                }
                if (go){
                    ans[ct] = j;
                    relation(map, ans, ct+1, n, m, j);
                }
            }
        }
    }
    printf("no");
    exit(0);
}

int main(){
    int n, m;
    int map[101][101], ans[101];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &map[i][j]);
    
    relation(map, ans, 0, n, m, 0);

    return 0;
}