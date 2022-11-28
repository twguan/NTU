#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    int arr[7];
    int ct;

    for (int i = 0; i < 7; ++i){
        scanf("%d", &arr[i]);
        printf("%d ", arr[i]);
        ct++;
    }
    printf("\n ct:%d", ct);
    return 0;
}