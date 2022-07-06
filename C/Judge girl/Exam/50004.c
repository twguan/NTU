#include <stdio.h>

int main(){
    int map[6][6];
    int next;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            map[i][j] = -1;

    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            scanf("%d", &map[i][j]);

    int win = 1;
    scanf("%d", &next);
    while(next){
        int go = 0;
        win = 1;
        for (int i = 1; i <=4; i++){
            for (int j = 0; j <= 4; j++){
                if (map[i][j] == next){
                    if (map[i+1][j] == 0){
                        map[i+1][j] = next;
                        map[i][j] = 0;
                        go = 1;
                        break;
                    }
                    else if (map[i-1][j] == 0){
                        map[i-1][j] = next;
                        map[i][j] = 0;
                        go = 1;
                        break;
                    }
                    else if (map[i][j+1] == 0){
                        map[i][j+1] = next;
                        map[i][j] = 0;
                        go = 1;
                        break;
                    }
                    else if (map[i][j-1] == 0){
                        map[i][j-1] = next;
                        map[i][j] = 0;
                        go = 1;
                        break;
                    }
                }
            }
            if (go)
                break;
        }
        int ct = 1;
        for (int i = 1; i <= 4; i++){
            for (int j = 1; j <= 4; j++){
                if (map[i][j] != ct)
                    win = 0;
                if (ct == 15)
                    ct = 0;
                else
                    ct++;
            }
        }
        if (win)
            break;

        scanf("%d", &next);
    }

    for (int i = 1; i <= 4; i++){
        for (int j = 1; j <= 4; j++){
            if (j == 1)
                printf("%d", map[i][j]);
            else
                printf(" %d", map[i][j]);
        }
        printf("\n");
    }
    if (next != 0)
        printf("1 %d", next);
    else
        printf("0");
    return 0;
}