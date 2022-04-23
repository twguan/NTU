#include <stdio.h>

int main(){
    int m, i, j, array[100];
    scanf("%d", &m);
    for(i = 2; i < m + 1; ++i){
        array[i] = 0;
    }
    i = 2;
    while(i*i < m){
        while(array[i] == 1)
            i++;
        for(j = 2*i; j <= m; j += i)
            array[j] = 1;
        i++;
    }
    for(i = 2; i < m + 1; ++i){
        if(array[i] == 0)
            printf("%d is prime\n", i);
    }
    return 0;
}