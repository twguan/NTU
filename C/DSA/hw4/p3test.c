#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct save{
    int ta;
    int tb;
}save;


typedef struct ds{
    struct ds *parent;
    int num;
    int size;
}ds;

ds* createDs(int num){
    ds *newDs = malloc(sizeof(ds));
    newDs->parent = newDs;
    newDs->num = num;
    newDs->size = 1;

    return newDs;
}

int findSet(ds **sets, int i){
    while (sets[i]->parent != sets[i])
        i = sets[i]->parent->num;

    return sets[i]->num;
}

int merge(ds **sets, int ta, int tb){
    int a = findSet(sets, ta), b = findSet(sets, tb);
    printf("%d %d\n", a, b);
    if (a == b)     // merge failure
        return 0;

    else{
        if (sets[a]->size >= sets[b]->size){
            sets[b]->parent = sets[a];
            sets[a]->size += sets[b]->size;
            // return b -> a, a.size += b.size
        }
        else {
            sets[a]->parent = sets[b];
            sets[b]->size += sets[a]->size;
            // return a -> b, b.size += a.size
        }
        return 1;
    }
}

int reverse(ds **sets, int ta, int tb){
    int a = findSet(sets, ta), b = findSet(sets, tb);
    if (a == b){    //same set
        if (sets[ta]->size >= sets[tb]->size){
            sets[tb]->parent = sets[tb];
            sets[ta]->size -= sets[tb]->size;
            // return b -> a, a.size += b.size
        }
        else {
            sets[ta]->parent = sets[ta];
            sets[tb]->size -= sets[ta]->size;
            // return a -> b, b.size += a.size
        }
        return 1;
    }
    else
        return 0;
}


void printDs(ds **sets, int n){
    for (int i = 1; i < n; i++)
        printf("ds %d: p= %d, size= %d\n", i, sets[i]->parent->num, sets[i]->size);
}

int main(){
    int N, M, q;
    char order[16];
    scanf("%d%d", &N, &M);
    ds **sets = malloc(sizeof(ds*) * N+1);
    for (int i = 0; i < N+1; i++)
        sets[i] = createDs(i);
    q = N;
    printDs(sets, N+1);
    for (int i = 0; i < M; i++){
        scanf("%s", order);
        if (!strcmp(order, "merge")){
            int a, b;
            scanf("%d%d", &a, &b);
            if(merge(sets, a, b))
                q--;
        }
        else if (!strcmp(order, "query")){
            printf("%d\n", q);
        }
        else if (!strcmp(order, "boom")){
            int a;
            scanf("%d", &a);
            
        }
        else if (!strcmp(order, "re")){
            int a, b;
            scanf("%d%d", &a, &b);
            if(reverse(sets, a, b))
                q++;
        }
        printDs(sets, N+1);
    }
    return 0;
}