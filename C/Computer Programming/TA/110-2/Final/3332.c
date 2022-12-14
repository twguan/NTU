#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info{
    char Name[10];
    long ID;
    long income;
    long s;
    char safe[1000000];
}Info;

int main(){
    int t, N, I, G;
    scanf("%d", &t);
    for (int i = 0; i < t; i++){
        scanf("%d%d%d", &N, &I, &G);
        Info *people = (Info *)malloc(sizeof(Info) * N);
        for (int j = 0; j < N; j++)
            scanf("%s %d %ld %ld %s", people[j].Name, &people[j].ID, &people[j].income, &people[j].s, people[j].safe);
            
        for (int j = 0; j < I; j++){
            int go = 1;
            long tID, tempS;
            char tempSafe[1000000];
            scanf("%ld%ld%s", &tID, &tempS, tempSafe);
            for (int k = 0; k < N; k++){
                if (people[k].ID == tID && people[k].s == tempS && !strncmp(people[k].safe, tempSafe, tempS)){
                    printf("True\n");
                    go = 0;
                    break;
                }
            }
            if(go)
                printf("False\n");
        }
        for (int j = 0; j < G; j++){
            int tID;
            scanf("%d", &tID);
            for (int k = 0; k < N; k++){
                if (people[k].ID == tID){
                    printf("%s %ld\n", people[k].Name, people[k].income);
                    break;
                }
            }
        }
    }

    return 0;
}