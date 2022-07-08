#include <stdio.h>

int main(){
    int n;
    int seesaw[21];
    while (scanf("%d", &n) != EOF){
        int total = 0, tr = 0, tl = 0, num = 0, ans = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &seesaw[i]);
            total += seesaw[i];
            tr += (i+1)*seesaw[i];
        }
        for (int i = 0; i < n; i++){
            
        }
    }
    return 0;
}