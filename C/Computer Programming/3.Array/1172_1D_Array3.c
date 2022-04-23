#include <stdio.h>

int main(){
    int ay[5];
    for (int i = 0; i < 5; ++i)
        scanf("%d", &ay[i]);
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 4-i; ++j)
            if (ay[j] > ay[j+1]){
                int temp = ay[j];
                ay[j] = ay[j+1];
                ay[j+1] = temp;
            }
    for (int i = 0; i < 5; ++i){
        printf("%d\t", ay[i]);
        for (int j = 0; j < ay[i]; ++j)
            printf("*");
        printf("\n");
    }
    return 0;
}