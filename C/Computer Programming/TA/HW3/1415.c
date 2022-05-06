#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int main(){
    int list[500], ct = 0;
    char input[32];
    char filename[32] = "./";
    char line[16];
    char delims[] = ",";
    scanf("%s", input);
    strcat(filename, input);
    FILE *f = fopen(filename, "r");
    fscanf(f, "%s", line);
    while(1){
        char *ptr = NULL;
        fscanf(f, "%s", line);
        if (feof(f))
            break;

        int id, score;
        double adj;
        ptr = strtok(line, delims);
        id = atoi(ptr);
        ptr = strtok(NULL, delims);
        score = atoi(ptr);
        adj = sqrt(score) * 11;
        if (adj < 60){
            list[ct] = id;
            ct++;
        }
    }
    qsort(list, ct, sizeof(int), cmp);
    printf("%d", list[0]);
    for (int i = 1; i < ct; i++)
        printf(" %d", list[i]);
    fclose(f);
    return 0;
}