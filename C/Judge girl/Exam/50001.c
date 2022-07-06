#include <stdio.h>
#include <stdlib.h>
int main(){
    int a, b, c, d, e, x, y, F;
    int p, q, r, s;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    scanf("%d%d%d%d", &p, &q, &r, &s);
    scanf("%d%d%d", &x, &y, &F);
    int money = 0;
    int travel = 1;
    for (int i = 0; i < F; i++){

        // remember abs !
        int dir = abs((a*x + b*y) % 4);
        if (!((x == p && y == q) || (x == r && y == s)))
            money += (c*x + d*y ) % e;

        if (dir == 0)
            y++;
        else if (dir == 1)
            x++;
        else if (dir == 2)
            y--;
        else if (dir == 3)
            x--;

        if (x == p && y == q){
            x = r;
            y = s;
        }
        else if (x == r && y == s){
            x = p;
            y = q;
        }
    }
    if (!((x == p && y == q) || (x == r && y == s)))
        money += (c*x + d*y ) % e;
    printf("%d\n%d %d", money, x, y);
    return 0;
}