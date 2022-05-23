#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b){
    char *sa = (char *)a;
    char *sb = (char *)b;
    return strcmp(sa, sb);
}

int main(){

    char list_name[32];
    char store_name[32];
    char note_name[32] = "note";

    char list[256][65];
    scanf("%s", list_name);
    scanf("%s", store_name);
    char *s = strstr(list_name, "list");
    strcat(note_name, s+4);
    
    FILE *list_f = fopen(list_name, "r");
    FILE *store_f = fopen(store_name, "r");
    FILE *note_f = fopen(note_name, "w");

    // scan the list
    int ct = 0;
    while (1){
        fscanf(list_f, "%s ", list[ct]);
        ct++;
        if (feof(list_f))
            break;
    }
    qsort(list, ct, sizeof(list[0]), cmp);
    
    int num, sum = 0, ct2 = 0;
    fscanf(store_f , "%d", &num);
    char **book = (char **)malloc(sizeof(char*) * num);
    for (int i = 0; i < num; i++)
        book[i] = (char *)malloc(sizeof(char) * 65);

    int *cost = (int *)malloc(sizeof(int) * num);

    for (int i = 0; i < num; i++)
        fscanf(store_f, "%s %d", book[i], &cost[i]);

    for (int i = 0; i < ct; i++){
        for (int j = 0; j < num; j++){
            if (!strcmp(list[i], book[j])){
                fprintf(note_f, "%s %d\n", list[i], cost[j]);
                sum += cost[j];
                break;
            }
            else if (strcmp(list[i], book[j]) < 0){
                fprintf(note_f, "%s None\n", list[i]);
                break;
            }
            if (j == num-1)
                fprintf(note_f, "%s None\n", list[i]);
        }
    }

    printf("%d", sum);
    fclose(list_f);
    fclose(store_f);
    fclose(note_f);

    return 0;
}