#include <stdio.h>

int main(){
    int r, c, map[502][502];
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            scanf("%d", &map[i][j]);
    
    // row check
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c-3+1; j++)
            if (map[i][j] == map[i][j+1] && map[i][j+1] == map[i][j+2]){
                map[i][j] = 0;
                map[i][j+1] = 0;
                map[i][j+2] = 0;
                j += 2;
            }
    // col check
    for (int j = 1; j <= c; j++)
        for (int i = 1; i <= r-3+1; i++)
            if (map[i][j] == map[i+1][j] && map[i+1][j] == map[i+2][j]){
                map[i][j] = 0;
                map[i+1][j] = 0;
                map[i+2][j] = 0;
                i += 2;
            }
    

    for (int i = 1; i <= r; i++){
        for (int j = 0; j <= c; j++){
            if (!map[i][j])
                continue;
            int num = map[i][j], ct = 0;
            if (num == map[i+1][j])
                ct++;
            if (num == map[i][j+1])
                ct++;
            if (num == map[i-1][j])
                ct++;
            if (num == map[i][j-1])
                ct++;
            if (ct == 2){
                map[i][j] = 0;
                if (num == map[i+1][j])
                    map[i+1][j] = 0;
                if (num == map[i][j+1])
                    map[i][j+1] = 0;
                if (num == map[i-1][j])
                    map[i-1][j] = 0;
                if (num == map[i][j-1])
                    map[i][j-1] = 0;
            }
        }
    }
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }
    return 0;
}