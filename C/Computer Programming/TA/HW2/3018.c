#include <stdio.h>

int main(){
    int arr[5][3];
    int total = 0, max = 0, idx;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &arr[i][j]);

    for (int i = 0; i < 5; i++){
        printf("student %d\n", i+1);
        int sum = 0;
        for (int j = 0; j < 3; j++){
            printf(" %d: %d\n", j+1, arr[i][j]);
            sum += arr[i][j];
        }
        printf(" sum: %d\n avg: %.2f\n", sum, sum / 3.0);
        total += sum;
        if (sum > max){
            idx = i;
            max = sum;
        }
    }
    printf("total: %d, avg: %.2f\n", total, total / 15.0);
    printf("highest avg: student %d: %.2f", idx+1, max / 3.0);
    return 0;
}