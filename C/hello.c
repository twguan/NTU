#include <stdio.h>

int main(){
    int c[6] = {2,0,2,3,0,1};
    int sum = 0, temp;
    for (int i = 0; i < 6; i++){
        temp = c[i];
        c[i] = sum;
        sum += temp;
    }

    for (int i = 0; i < 6; i++)
        printf("%d ", c[i]);
    return 0;
}