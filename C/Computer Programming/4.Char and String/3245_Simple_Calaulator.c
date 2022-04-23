#include <stdio.h>

int main(){
    int n, minus = 0, sum = 0;
    scanf("%d", &n);
    int num[n];
    char sym[n-1];
    for(int i = 0; i < n-1; ++i){
        scanf("%d", &num[i]);
        scanf(" %c", &sym[i]);
    }
    scanf("%d", &num[n-1]);
    for (int i = 0; i < n-1; ++i){
        if (sym[i] == '*'){
            num[i+1] *= num[i];
            num[i] = 0;
        }
    }
    for (int i = 0; i < n; ++i){
        if (minus && num[i]){
            num[i] *= -1;
            minus = 0;
        }
        if (sym[i] == '-')
            minus = 1;
            
    }
    for (int i = 0; i < n; ++i)
        sum += num[i];
    printf("%d", sum);
    return 0;
}