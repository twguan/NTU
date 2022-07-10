#include <stdio.h>

int main(){
    int n, number = 0;
    int stack[5], ptr = 0, op[5], ptr2 = 0;
    while (scanf("%d", &n) != EOF){
        if (n == 8 || n == 9 || n == 0){
            stack[ptr++] = number;
            number = 0;
            if (n == 0)
                break;
            
            while (ptr2 != 0 && op[ptr2-1] >= n){
                if (op[ptr2-1] == 8)
                    stack[ptr-2] += stack[ptr-1];
                else
                    stack[ptr-2] *= stack[ptr-1];
                ptr2--;
                ptr--;
            }
            op[ptr2++] = n;
        }
        else{
            number *= 10;
            number += n;
        }
    }
    while (ptr2){
        if (op[ptr2-1] == 8)
            stack[ptr-2] += stack[ptr-1];
        else
            stack[ptr-2] *= stack[ptr-1];
        ptr2--;
        ptr--;
    }
    // for (int i = 0; i < ptr2; i++)
    //     printf("%d ", op[ptr2]);
    // printf("ptr:%d, ptr2:%d", ptr, ptr2);
    printf("%d", stack[0]);
    return 0;
}