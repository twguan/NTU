#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int n, num[15] = {0}, ct = 0, number, max = 0, pos;
    scanf("%d", &n);
    char food[15][30] = {"\0"}, temp[15];
    for (int i = 0; i < n; ++i){
        int go = 1;
        scanf("%s %d", temp, &number);
        for (int j = 0; j < ct; ++j){
            if (!strcmp(temp, food[j])){
                num[j] += number;
                go = 0;
                break;
            }
        }
        if (go){
            strcpy(food[ct], temp);
            num[ct] += number;
            ct++;
        }
    }
    for (int i = 0; i < ct; ++i){
        if (num[i] > max){
            max = num[i];
            pos = i;
        }
    }
    printf("%s %d", food[pos], num[pos]);
    return 0;
}