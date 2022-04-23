#include <stdio.h>

int main(){
    int n, i, count1, count2;
    while(scanf("%d", &n) != EOF){
    count1 = 0;
    count2 = 0;
    for (i = 0; i < 32; ++i){
        if ((n>>i) & 1)
            count1++;
        else {
            if (count1 > count2)
                count2 = count1;
            count1 = 0;
        }
    }
    if (count2 == 0)
        count2 = count1;
    printf("%d\n", count2);
    }
    return 0;
}