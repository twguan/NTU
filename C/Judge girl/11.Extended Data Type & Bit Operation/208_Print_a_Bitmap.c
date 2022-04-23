#include <stdio.h>

int main(){
    int h, w, i, j, n, count;
    count = 0;
    scanf("%d %d", &h, &w);
    n = (h*w-1)/32+1;
    int a[h*w];
    char pos, neg;
    scanf(" %c", &pos);
    scanf(" %c", &neg);
    for (i = 0; i < n; ++i){
        unsigned int input;
        scanf("%u", &input);
        for (j = 0; j < 32; ++j){
            if (count > h*w)
                break;
            if (input<<j & (1<<31))
                a[count] = 1;
            else 
                a[count] = 0;
            count++;
        }
    }
    for (i = 0; i < h*w; ++i){
        if(a[i])
            printf("%c", pos);
        else
            printf("%c", neg);
        if (i%h == (h-1))
            printf("\n");
    }   
    return 0;
}