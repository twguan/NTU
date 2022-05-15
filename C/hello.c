#include <stdio.h>



int main(){
    int len = 5, ct = 1;
    int l[5] = {0,1,1,3,5};
    for (int i = 0; i < len-1; i++){
        if (l[i] != l [i+1]){
            printf("ct= %d ", ct);
            ct = 1;
        }
        else
            ct++;
    }
    return 0;
}