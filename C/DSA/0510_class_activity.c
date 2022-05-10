#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct disjointSet{
    // TODO: Determine fields to use by your method
    struct disjointSet *parent;
    int num;
    int size;
} DisjointSet;

DisjointSet ds[1 << 24];
bool set[1 << 24] = {};

int c2i(char c) { 
    if ('0' <= c && c <= '9') return c - '0';
    else if ('a' <= c && c <= 'z') return c - 'a' + 10;
    else if ('A' <= c && c <= 'Z') return c - 'A' + 36;
    return -1;
}

int hash(const char* s) {  
    int ret = 0;
    int mask = (1<<24)-1;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        ret = mask & (ret << 4) | c2i(s[i]);
    return ret;
}

void makeset(int h){
    // TODO: Initialize a set with hash value
    ds[h].parent = &ds[h];
    ds[h].num = h;
    ds[h].size = 1;
}

inline void static init(int i) {
    if (!set[i]) {
        makeset(i);
        set[i] = 1;
    }
}

int find_set(int i) {
    init(i);
    // TODO: Implement your find algorithm here
    // Do path compression
    if (ds[i].parent != &ds[i]){
        ds[i].parent = &ds[find_set(ds[i].parent->num)];
    }
    return ds[i].parent->num;
}

void group(int ra, int rb) {
    int a = find_set(ra), b = find_set(rb);
    // TODO: Implement your union algorithm here
    if (ds[a].size >= ds[b].size){
        ds[b].parent = &ds[a];
        ds[a].size += ds[b].size;
    }
    else{
        ds[a].parent = &ds[b];
        ds[b].size += ds[a].size;
    }
}

bool same_set(int a, int b) {
    // TODO: Implement your algorithm here
    return(find_set(a) == find_set(b));
}

int main() {
    // TODO: Implement your algorithm here
    int n;
    char order[12], student_A[16], student_B[16];
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%s%s%s", order, student_A, student_B);
        int a = hash(student_A);
        int b = hash(student_B);
        if (!strcmp(order, "group")){
            group(a, b);
        }
        else if(!strcmp(order, "test")){
            if(same_set(a, b))
                printf("Positive\n");
            else
                printf("Negative\n");
        }
    }
}