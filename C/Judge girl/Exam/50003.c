#include <stdio.h>
#include <stdlib.h>


// vertical = 1, horizontal = 2, diagonal = 3, none = 0;
int judge(int px, int py, int nx, int ny){
    if (px == nx)
        return 1;
    else if (py == ny)
        return 2;
    else if (abs(nx-px) == abs(ny-py))
        return 3;
    else
        return 0;
}


int main(){
    int l, x, y;
    scanf("%d%d%d", &l, &x, &y);
    int map[101][101] = {};
    for (int i = 0; i < l; i++){
        int n, px, py;
        scanf("%d%d%d", &n, &px, &py);
        for (int j = 1; j < n; j++){
            int nx, ny, op;
            scanf("%d%d", &nx, &ny);
            op = judge(px, py, nx, ny);
            // printf("%d\n", op);
            if (op == 1){
                int ct = ny-py;
                if (ct >= 0){
                    for (int k = 0; k <= ct; k++)
                        map[px][py+k] = 1;
                }
                else{
                    for (int k = 0; k <= -ct; k++)
                        map[px][ny+k] = 1;
                }
            }
            else if (op == 2){
                int ct = nx-px;
                if (ct >= 0){
                    for (int k = 0; k <= ct; k++)
                        map[px+k][py] = 1;
                }
                else{
                    for (int k = 0; k <= -ct; k++)
                        map[nx+k][py] = 1;
                }
            }
            else if (op == 3){
                int a = nx-px;
                int b = ny-py;
                if (a == b){
                    if (a >= 0){
                        for (int k = 0; k <= a; k++)
                            map[px+k][py+k] = 1;
                    }
                    else{
                        for (int k = 0; k <= -a; k++)
                            map[nx+k][ny+k] = 1;
                    }
                }
                else if (a == -b){
                    if (a >= 0){
                        for (int k = 0; k <= a; k++)
                            map[px+k][py-k] = 1;
                    }
                    else{
                        for (int k = 0; k <= -a; k++)
                            map[nx+k][ny-k] = 1;
                    }
                }
            }
            else{
                printf("ERROR %d %d", i+1, j+1);
                return 0;
            }
            px = nx;
            py = ny;
        }
    }


    for (int j = x-1; j >= 0; j--){
        for (int i = 0; i < y; i++)
            printf("%d", map[i][j]);
        printf("\n");
    }
    return 0;
}