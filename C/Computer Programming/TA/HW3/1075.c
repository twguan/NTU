#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp ( const void *a , const void *b ){ 
    return *(int *)a - *(int *)b; 
}

int main(){
    int num[10000], ct = 0, temp;
    char filename[32];
    char name1[32] = "../app/";
    char name2[32] = "../app/";
    scanf("%s", filename);
    strcat(name1, filename);
    FILE* f = fopen(name1, "r");
    while (fscanf(f, "%d", &temp) != EOF){
        num[ct] = temp;
        ct++;
    }
    scanf("%s", filename);
    strcat(name2, filename);
    f = fopen(name2, "r");
    while (fscanf(f, "%d", &temp) != EOF){
        num[ct] = temp;
        ct++;
    }
    qsort(num, ct, sizeof(int), cmp);
    for (int i = 0; i < ct; i++)
        printf("%d ", num[i]);
    printf("\n");
    return 0;
}