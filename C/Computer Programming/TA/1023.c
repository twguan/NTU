#include <stdio.h>

int main(){
    int n, max = 0, min = 3000, posm = 0, posn = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        if (arr[i] > max){
            max = arr[i];
            posm = i;
        }
        if (arr[i] < min){
            min = arr[i];
            posn = i;
        }
    }
    printf("%d %d\n%d %d\n", posm+1, max, posn+1, min);
    return 0;
}