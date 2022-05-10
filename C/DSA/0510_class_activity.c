#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct disjointSet{
    // TODO: Determine fields to use by your method
    struct disjointSet *parent;
    char name[16];
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

void makeset(const char* s){
    // TODO: Initialize a set with hash value
    int h = hash(s);
    ds[h].parent = &ds[h];
    strcpy(ds[h].name, s);
    ds[h].size = 1;
}

inline void static init(const char* s) {
    int i = hash(s);
    if (!set[i]) {
        makeset(s);
        set[i] = 1;
    }
}

int find_set(const char* s) {
    init(s);
    int i = hash(s);
    // TODO: Implement your find algorithm here
    // Do path compression
    if (ds[i].parent->parent != &ds[i]){
        find_set(ds[i].parent->name);
        ds[i].parent = ds[i].parent->parent;
    }
    return hash(ds[i].parent->name);
}

void group(const char *ra, const char *rb) {
    int a = find_set(ra), b = find_set(rb);
    // TODO: Implement your union algorithm here
    if (ds[a].size > ds[b].size){
        ds[b].parent = &ds[a];
    }
    else{
        ds[a].parent = &ds[b];
    }
}

bool same_set(const char*a, const char* b) {
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
        if (!strcmp(order, "group")){
            group(student_A, student_B);
        }
        else if(!strcmp(order, "test")){
            if(same_set(student_A, student_B))
                printf("Positive\n");
            else
                printf("Negative\n");
        }
    }
}