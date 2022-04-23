#include <stdio.h>

int main(){
    int n, m, l, r, input;
    scanf("%d%d", &n, &m);
    int list[100001] = {0};
    for (int i = 1; i <= n; i++){
        scanf("%d", &input);
        list[i] = list[i-1] + input;
    }
    for (int i = 0; i < m; i++){
        scanf("%d %d", &l, &r);
        printf("%d\n", list[r] - list[l-1]);
    }
    return 0;
}