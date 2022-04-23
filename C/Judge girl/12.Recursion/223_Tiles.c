#include <stdio.h>

int index2(int n){
    int m = 0;
    while (n > 1){
        n /= 2;
        m++;
    }
    return m;
}   
int isrotate(int type, int ro){
    if (ro == 1){
        switch (type){
            case 1:
                type = 4;
                break;
            case 2:
                type = 3;
                break;
            case 3:
                type = 2;
                break;
            case 4:
                type = 1;
        }
    }
    if (ro == 2){
        switch (type){
            case 1:
                type = 2;
                break;
            case 2:
                type = 1;
                break;
            case 3:
                type = 4;
                break;
            case 4:
                type = 3;
        }
    }
    return type;
}
void pos_order(int x, int y, int n, int type, int pos[3][2]){
    if (type == 1){
        pos[0][0] = x - n; pos[0][1] = y + n;
        pos[1][0] = x - n; pos[1][1] = y - n;
        pos[2][0] = x + n; pos[2][1] = y - n;
    }
    if (type == 4){
        pos[0][0] = x - n; pos[0][1] = y - n;
        pos[1][0] = x - n; pos[1][1] = y + n;
        pos[2][0] = x + n; pos[2][1] = y + n;
    }
    if (type == 2){
        pos[0][0] = x + n; pos[0][1] = y + n;
        pos[1][0] = x + n; pos[1][1] = y - n;
        pos[2][0] = x - n; pos[2][1] = y - n;
    }
    return;
}
void fill(int x, int y, int l, int type, int ro){
    //no change ro = 0, ud = 1, lr = 2
    int i, n = 1;
    for (i = 0; i < l-2; ++i)
        n *= 2;
    type = isrotate(type, ro);
    if (l == 1){
        printf("%d %d %d\n", type, x, y);
        return;
    }
    int pos[3][2];
    pos_order(x, y, n, type, pos);
    fill(x, y, l-1, type, 0);
    fill(pos[1][0], pos[1][1], (l-1), type, 0);
    fill(pos[0][0], pos[0][1], (l-1), type, 1);
    fill(pos[2][0], pos[2][1], (l-1), type, 2);
}
int main(){
    int m, n, i, lv, c, times;
    scanf("%d%d", &m, &n);
    lv = index2(m);
    times = index2(m)-index2(n);
    c = m / 2;
    for (i = 0; i < times; ++i){
        fill(c, c, lv, 1, 0);
        lv -= 1;
        c += m/4;
        m /= 2;
    }
    return 0;
}