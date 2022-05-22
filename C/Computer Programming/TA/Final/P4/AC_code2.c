#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int cmp(const void *a, const void *b){
    char *sa = (char *)a;
    char *sb = (char *)b;
    return strcmp(sa, sb);
}

int main(){
    clock_t start, end;
    // start record the time
    start = clock();

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
    
    int num, cost, sum = 0, ct2 = 0;
    char book[65];
    fscanf(store_f , "%d", &num);
    for (int i = 0; i < num; i++){
        fscanf(store_f, "%s %d", book, &cost);
        if (ct2 == ct)
            break;
        while(strcmp(list[ct2], book) <= 0){     // book > ct2
            if(!strcmp(list[ct2], book)){
                fprintf(note_f, "%s %d\n",list[ct2], cost);
                sum += cost;
                ct2++;
                if (ct2 == ct)
                    break;
            }
            else{
                fprintf(note_f, "%s None\n", list[ct2]);
                ct2++;
                if (ct2 == ct)
                    break;
            }
        }
    } 
    for (int i = ct2; i < ct; i++)
        fprintf(note_f, "%s None\n", list[i]);
    printf("%d", sum);
    fclose(list_f);
    fclose(store_f);
    fclose(note_f);

    end = clock();
    double diff = end - start;
    printf("\nexecute %.0f ms", diff);
    return 0;
}