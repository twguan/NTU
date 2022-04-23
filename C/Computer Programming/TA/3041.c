#include <stdio.h>

int main(){
    int n, m, go = 1;
    scanf("%d %d", &n, &m);
    for (int i = n; i <= m; i++){
        int x = i, ans = 0, digit = 1;
        while(x >= 10){
            x /= 10;
            digit++;
        }
        x = i;
        for (int j = 0; j < digit; j++){
            int a = x % 10;
            int y = 1;
            x /= 10;
            for (int k = 0; k < digit; k++){
                y *= a;
            }
            ans += y;
        }
        if (ans == i){
            if (go){
                printf("%d", i);
                go = 0;
            }
            else
                printf(" & %d", i);
        }
    }
    if (go)
        printf("none");
    return 0;
}