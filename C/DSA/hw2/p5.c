#include <stdio.h>
#include <stdlib.h>

#include "price.h"

typedef unsigned long long ULL;

typedef struct node{
    ULL num;
    int index;
}node;

void Heapify(node *A, int n, int i){
    int min = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && A[l].num < A[min].num)
        min = l;
    if (r < n && A[r].num < A[min].num)
        min = r;
    if (min != i){
        node temp = A[i];
        A[i] = A[min];
        A[min] = temp;

        Heapify(A, n, min);
    }
}

void Build_Min_Heap(node *A, int n){
    int start = n/2 - 1;
    for (int i = start; i >= 0; i--)
        Heapify(A, n, i);
}

node Delete(node *A, int *n){
    node d = A[0];
    A[0] = A[*n-1];
    *n -= 1;
    // printf("Delete %d from %d\n", d.num, d.index);
    Heapify(A, *n, 0);
    return d;
}

void Insert(node *A, int *n, node i){
    // printf("Insert %d\n", i.num);
    A[*n] = i;
    int cursor = *n;
    while(cursor > 0){
        int min = A[cursor].num;
        if (min > A[(cursor-1)/2].num)
            break;
        else{
            node temp = A[cursor];
            A[cursor] = A[(cursor-1)/2];
            A[(cursor-1)/2] = temp;
            cursor = (cursor-1) / 2;
        }
    }
    *n += 1;
}

// int price(int s, int t){
//     return s+t;
// }

int main(){

    int A, Q, N, s, k;
    scanf("%d%d%d", &A, &Q, &N);
    int *stock = (int *)malloc(sizeof(int) * A);
    int *days = (int *)malloc(sizeof(int) * A);
    // construct min heap
    node *list = (node *)malloc(sizeof(node) * A * N);

    for (int i = 0; i < A; i++){
        scanf("%d", &stock[i]);
        for (int l = 0; l < N; l++){
            list[i*N + l].num = price(stock[i], l+1);
            list[i*N+l].index = i;
            days[i] = 1+N;
        }
    }
    int len = A*N;
    Build_Min_Heap(list, len);

    node *sort = (node *)malloc(sizeof(node) * 1000002);
    for (int i = 0; i < Q; i++){
        scanf("%d%d", &s, &k);

        // find kth smallest
        static int j = 0;
        for (j; j < k; j++){
            //  delete root
            sort[j] = Delete(list, &len);
            int arrnum = sort[j].index;
            //  insert from stock[index]
            node new;
            new.index = arrnum;
            new.num = price(stock[arrnum], days[arrnum]);
            days[arrnum] += 1;
            Insert(list, &len, new);
        }

        if (s){     //if we have new stock

        }
        else
            printf("%llu\n", sort[k-1].num);
    }
    free(sort);
    return 0;
}