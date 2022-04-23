#include <stdio.h>

int main(){
    int n, height[3000], order[3000], i, k = -1, w = 99999999, now, wtemp;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &height[i]);
    for (i = 0; i < n; ++i)
        scanf("%d", &order[i]);
    for (i = 0; i < n; ++i){
        now = i;
        int end = i-1, go = 1, count = 0;
        if (end < 0)
            end = n-1;
        wtemp = 0;
        while (now != end){
            if (order[now] == 0 || count > n){
                go = 0;
                break;
            }
            int next = now + order[now];
            if (next >= n)
                next -= n;
            if (height[now] < height[next])
                wtemp += height[next] - height[now];
            now = next;
            count++;
        }
        if (go){
            if (wtemp < w){
                w = wtemp;
                k = i;
            }
        }
    }
    if (k == -1)
        printf("-1\ninf");
    else
        printf("%d\n%d", k, w);
    return 0;
}