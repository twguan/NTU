#include <stdio.h>



int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    int tortoise = A[0], hare = A[0];
    while (1){
        tortoise = A[tortoise];
        hare = A[A[hare]];
        if (tortoise == hare)
            break;
    }
        int ptr1 = A[0], ptr2 = hare;
        while(ptr1 != ptr2){
            ptr1 = A[ptr1];
            ptr2 = A[ptr2];
        }
        printf("%d", ptr1);
    return 0;
}