#include <stdio.h>

void swap(int *bits, int len, int start){
    if(len == 1)
        return;

    int num = 0;
    for (int i = start; i < start+len; i++)
        if (bits[i])
            num++;
    
    if (num % 2){
        for (int i = start; i < start + len / 2; i++){
            int temp = bits[i];
            bits[i] = bits[i+len/2];
            bits[i+len/2] = temp;
        } 
    }
    // for (int i = start; i < start+len; i++)
    //     printf("%d", bits[i]);
    // printf("\n");
    swap(bits, len/2, start);
    swap(bits, len/2, start+len/2);
}


int main(){
    unsigned int n;
    scanf("%u", &n);
    int bits[32];
    for (int i = 31; i >= 0; i--){
        bits[i] = n % 2;
        n /= 2;
    }
    swap(bits, 32, 0);

    n = 0;
    for (int i = 0; i < 31; i++){
        if(bits[i])
            n++;
        n *= 2;
    }
    if (bits[31])
        n++;
    // printf("\n");
    printf("%u", n);
    // for (int i = 0; i < 32; i++)
    //     printf("%d", bits[i]);
    return 0;
}