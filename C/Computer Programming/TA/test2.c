#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    clock_t start, end;
    start = clock();
    FILE *f = fopen("0.txt", "w");
    for (int i = 0; i < 100000; i++){
        fprintf(f, "%d ", i);
    }
    fclose(f);
    end = clock();
    double diff = end - start;
    printf("execute %f ms", diff);
}